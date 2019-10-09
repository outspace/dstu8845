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

    uint8_t out[1024 * 1024] = { 0 };

    clock_t begin = clock();

    for (int i = 0; i < 1024 * 5; i++) {
        dstu8845_crypt(ctx, out, 1024 * 1024, out);
    }

    clock_t end = clock();


    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Encrypted 5GB in %f seconds\n", time_spent);
    printf("Speed is %f Gb/s\n",((1 / ((time_spent * 1.0) / 5)) * 8));

    dstu8845_free(ctx);

    return 0;
}
