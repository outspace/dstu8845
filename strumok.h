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

#ifndef STRUMOK_H
#define STRUMOK_H

#include <stdint.h>
#include <string.h>

#define STRUMOK_EXPORTS

#ifdef _WIN32
#    define STRUMOK_API __declspec(dllexport)
#else
#    define STRUMOK_API __attribute__((visibility("default")))
#endif

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct Dstu8845Ctx_st Dstu8845Ctx;

STRUMOK_API Dstu8845Ctx *dstu8845_alloc();

STRUMOK_API int dstu8845_init(Dstu8845Ctx *ctx, const uint64_t *key, uint8_t key_size, const uint64_t *iv);

STRUMOK_API int dstu8845_set_iv(Dstu8845Ctx *ctx, const uint64_t *iv);

STRUMOK_API int dstu8845_crypt(Dstu8845Ctx *ctx, const uint8_t *in, size_t inl, uint8_t *out);

STRUMOK_API void dstu8845_free(Dstu8845Ctx *ctx);

#ifdef  __cplusplus
}
#endif

#endif
