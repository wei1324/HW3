#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include "../console.h"

long long power(long long base, unsigned int exponent)
{
    if (exponent == 1 || base == 0 || base == 1) {
        return base;
    }
    if (base == -1) {
        return exponent % 2 == 0 ? 1 : -1;
    }
    if (exponent >= sizeof(long long) * CHAR_BIT) {
        errno = ERANGE;
        return 0;
    }

    long long previous = power(base, exponent - 1);
    if (errno == ERANGE ||
        (base > 1 && (previous > LLONG_MAX / base || previous < LLONG_MIN / base)) ||
        (base < -1 && (previous > LLONG_MIN / base || previous < LLONG_MAX / base))) {
        errno = ERANGE;
        return 0;
    }
    return base * previous;
}

int main(void)
{
    use_utf8_console();
    long long base, exponent;
    char line[80], extra;
    fputs(u8"請輸入整數底數和正整數指數，以空格分隔（例如 3 4）：", stderr);
    fflush(stderr);
    if (!fgets(line, sizeof line, stdin) ||
        sscanf(line, "%11lld%*1[ \t] %11lld %c", &base, &exponent, &extra) != 2 ||
        base < INT_MIN || base > INT_MAX || exponent < 1 || exponent > UINT_MAX) {
        fputs(u8"輸入錯誤。底數須在 int 範圍內，指數須為正整數且在 unsigned int 範圍內。\n", stderr);
        return 1;
    }

    errno = 0;
    long long result = power(base, (unsigned int)exponent);
    if (errno == ERANGE) {
        fputs(u8"結果超出 long long 可表示的範圍。\n", stderr);
        return 1;
    }
    printf("%lld\n", result);
    return 0;
}
