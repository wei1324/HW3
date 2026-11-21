#include <limits.h>
#include <stdio.h>
#include "../console.h"
#include <stdlib.h>

int main(void)
{
    use_utf8_console();
    long long seed;
    char line[80], extra;
    fputs(u8"請輸入亂數種子（非負整數，例如 67）：", stderr);
    fflush(stderr);
    if (!fgets(line, sizeof line, stdin) ||
        sscanf(line, "%11lld %c", &seed, &extra) != 1 || seed < 0 || seed > UINT_MAX) {
        fputs(u8"輸入錯誤。亂數種子須為非負整數且在 unsigned int 範圍內。\n", stderr);
        return 1;
    }

    srand((unsigned int)seed);
    for (int i = 1; i <= 10; ++i) {
        printf("%10d", 1 + rand() % 6);
        if (i % 5 == 0) {
            putchar('\n');
        }
    }
    return 0;
}
