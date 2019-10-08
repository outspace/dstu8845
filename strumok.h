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

STRUMOK_API int dstu8845_crypt(Dstu8845Ctx *ctx, const uint8_t *in, size_t inl, uint8_t *out);

STRUMOK_API void dstu8845_free(Dstu8845Ctx *ctx);

#ifdef  __cplusplus
}
#endif

#endif
