/*
 * Copyright (c) 2019, Mykola Baibuz <mykola.baibuz@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#include "strumok.h"
#include <stdio.h>
#include <time.h>

int main()
{
    Dstu8845Ctx *ctx = dstu8845_alloc();

    uint64_t key[8], iv[4];

    iv[0] = 1;
    iv[1] = 2;
    iv[2] = 3;
    iv[3] = 4;

    uint8_t key_size = 64;

    key[7] = 0x8000000000000000;
    key[6] = 0x0000000000000000;
    key[5] = 0x0000000000000000;
    key[4] = 0x0000000000000000;
    key[3] = 0x0000000000000000;
    key[2] = 0x0000000000000000;
    key[1] = 0x0000000000000000;
    key[0] = 0x0000000000000000;

    dstu8845_init(ctx, key, key_size, iv);

    uint8_t out[4096] = { 0 };

    clock_t begin = clock();

    for (int i = 0; i < 1024 * 15 * 256; i++) {
        dstu8845_crypt(ctx, out, 4096, out);
    }

    clock_t end = clock();


    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Encrypted 15GB in %f seconds\n", time_spent);
    printf("Speed is %f Gb/s\n", ((1 / ((time_spent * 1.0) / 15)) * 8));

    dstu8845_free(ctx);

    return 0;
}
