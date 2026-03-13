"""Filter Wine SEH debug log to remove OutputDebugString noise.

Usage: python filter_wine_log.py <input.log> [output.log]
If output is omitted, writes to stdout.
"""
import sys


def main():
    if len(sys.argv) < 2:
        print("Usage: python filter_wine_log.py <input.log> [output.log]", file=sys.stderr)
        sys.exit(1)

    input_path = sys.argv[1]
    output = open(sys.argv[2], 'w') if len(sys.argv) > 2 else sys.stdout

    total = kept = access_violations = debug_strings = 0
    with open(input_path) as f:
        for line in f:
            total += 1
            # Skip VEH handler call/return lines for OutputDebugString
            if 'handler at 008A8B70' in line:
                if 'code=40010006' in line or 'returned 0' in line:
                    continue
            # Skip 40010006 dispatch trace lines (but keep warn: lines with string content)
            if 'code=40010006' in line and 'warn:' not in line:
                continue
            # Count categories
            if 'c0000005' in line or 'EXCEPTION_ACCESS_VIOLATION' in line:
                access_violations += 1
            if 'warn:seh:dispatch_exception' in line and '"' in line:
                debug_strings += 1
            output.write(line)
            kept += 1

    summary = f"\n# Filtered: {kept}/{total} lines kept ({access_violations} AV lines, {debug_strings} debug strings)\n"
    output.write(summary)
    if output is not sys.stdout:
        output.close()
    print(summary, file=sys.stderr)


if __name__ == '__main__':
    main()
