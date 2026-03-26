#!/usr/bin/env python3
"""Generate a decomp.dev-style treemap progress image from an objdiff report."""

import json
import sys
from pathlib import Path

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import squarify


# ── Color scheme: clear gradient from gray → navy → blue → teal → green → gold ──

COLOR_TIERS = [
    # (min_pct, color,     label)
    (100,      "#FFD700",  "100% matched"),   # gold
    (95,       "#2ecc40",  "95-100%"),         # bright green
    (90,       "#1a8f1a",  "90-95%"),          # medium green
    (75,       "#0e6b2c",  "75-90%"),          # dark green
    (50,       "#1a6b6b",  "50-75%"),          # teal
    (25,       "#0c3795",  "25-50%"),          # dark blue
    (0.01,     "#0d1b3e",  "1-25%"),           # deep navy
    (0,        "#353535",  "Not started"),     # gray
]


def get_color(unit):
    """Color based on match percentage using tiered gradient."""
    meta = unit.get("metadata", {})
    measures = unit.get("measures", {})

    if meta.get("complete") or meta.get("auto_generated"):
        return "#FFD700"  # gold - complete

    pct = measures.get("matched_code_percent", 0)
    if pct is None:
        pct = 0

    for min_pct, color, _ in COLOR_TIERS:
        if pct >= min_pct:
            return color
    return "#353535"


def main():
    report_path = sys.argv[1] if len(sys.argv) > 1 else "cmake-build-presets/objdiff/report.json"
    output_path = sys.argv[2] if len(sys.argv) > 2 else "progress.png"

    with open(report_path) as f:
        report = json.load(f)

    measures = report["measures"]
    units = report["units"]

    # Prepare data for treemap
    sizes = []
    labels = []
    colors = []

    for unit in units:
        total_code = int(unit.get("measures", {}).get("total_code", 0) or 0)
        if total_code == 0:
            continue
        name = unit["name"]
        # Shorten the name for display
        short_name = name.split("/")[-1] if "/" in name else name
        sizes.append(total_code)
        labels.append(short_name)
        colors.append(get_color(unit))

    if not sizes:
        print("No units with code found!")
        return

    # Create figure
    fig, ax = plt.subplots(1, 1, figsize=(20, 12))
    fig.patch.set_facecolor("#1a1a2e")
    ax.set_facecolor("#1a1a2e")

    # Normalize sizes for squarify
    normed = squarify.normalize_sizes(sizes, 100, 60)
    rects = squarify.squarify(normed, 0, 0, 100, 60)

    for rect, label, color, size in zip(rects, labels, colors, sizes):
        x, y, dx, dy = rect["x"], rect["y"], rect["dx"], rect["dy"]
        ax.add_patch(plt.Rectangle(
            (x, y), dx, dy,
            facecolor=color,
            edgecolor="#0d0d1a",
            linewidth=0.5,
        ))
        # Only label large enough rectangles
        if dx > 2 and dy > 1.5:
            fontsize = min(8, max(4, min(dx, dy) * 0.8))
            # Use dark text on gold, white on everything else
            text_color = "#1a1a2e" if color == "#FFD700" else "white"
            ax.text(
                x + dx / 2, y + dy / 2,
                label,
                ha="center", va="center",
                color=text_color,
                fontsize=fontsize,
                fontweight="bold",
                alpha=0.85,
            )

    ax.set_xlim(0, 100)
    ax.set_ylim(0, 60)
    ax.set_aspect("equal")
    ax.axis("off")

    # Title with stats
    matched_code_pct = measures.get("matched_code_percent", 0)
    matched_funcs = measures.get("matched_functions", 0)
    total_funcs = measures.get("total_functions", 0)
    total_code = int(measures.get("total_code", 0))
    matched_code = int(measures.get("matched_code", 0))

    title = (
        f"Black & White Decompilation Progress\n"
        f"{matched_code_pct:.2f}% code matched  |  "
        f"{matched_funcs}/{total_funcs} functions  |  "
        f"{matched_code:,}/{total_code:,} bytes"
    )
    ax.set_title(title, color="white", fontsize=16, fontweight="bold", pad=20)

    # Legend — only include tiers that appear in the data
    used_colors = set(colors)
    legend_items = []
    for _, color, label in COLOR_TIERS:
        if color in used_colors:
            ec = "#1a1a2e" if color == "#FFD700" else "white"
            legend_items.append(mpatches.Patch(facecolor=color, edgecolor=ec, label=label))

    ax.legend(
        handles=legend_items,
        loc="lower right",
        fontsize=9,
        facecolor="#1a1a2e",
        edgecolor="#444",
        labelcolor="white",
        framealpha=0.9,
    )

    plt.tight_layout()
    plt.savefig(output_path, dpi=150, bbox_inches="tight", facecolor=fig.get_facecolor())
    plt.close()
    print(f"  Code: {matched_code_pct:.2f}% matched ({matched_code:,} / {total_code:,} bytes)")
    print(f"  Functions: {matched_funcs} / {total_funcs} ({matched_funcs/total_funcs*100:.2f}%)")


if __name__ == "__main__":
    main()
