/* adler32.cpp -- compute the Adler-32 checksum of a data stream
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h
 *
 * Clean C++ version - functionally correct, not byte-exact.
 * The byte-exact version is in src/c/zlib/adler32.c
 */

extern "C" {
#include "zlib.h"
}

static constexpr unsigned long BASE = 65521UL;
static constexpr int NMAX = 5552;

extern "C"
uLong ZEXPORT adler32(uLong adler, const Bytef *buf, uInt len)
{
    unsigned long s1 = adler & 0xffff;
    unsigned long s2 = (adler >> 16) & 0xffff;

    if (buf == Z_NULL)
        return 1UL;

    while (len > 0) {
        int k = (len < NMAX) ? static_cast<int>(len) : NMAX;
        len -= k;

        while (k >= 16) {
            for (int i = 0; i < 16; ++i) {
                s1 += buf[i];
                s2 += s1;
            }
            buf += 16;
            k -= 16;
        }

        while (k-- > 0) {
            s1 += *buf++;
            s2 += s1;
        }

        s1 %= BASE;
        s2 %= BASE;
    }

    return (s2 << 16) | s1;
}
