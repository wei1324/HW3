#include <stdint.h>
#include <stdio.h>
#include "../console.h"

static long long gcd(long long a, long long b)
{
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

long long lcm(int32_t a, int32_t b)
{
    if (a == 0 || b == 0) {
        return 0;
    }

    long long x = a < 0 ? -(long long)a : a;
    long long y = b < 0 ? -(long long)b : b;
    return (x / gcd(x, y)) * y;
}

int main(void)
{
    use_utf8_console();
    long long a, b;
    char line[80], extra;
    fputs(u8"請輸入兩個整數，以空格分隔（例如 12 18）：", stderr);
    fflush(stderr);
    if (!fgets(line, sizeof line, stdin) ||
        sscanf(line, "%11lld%*1[ \t] %11lld %c", &a, &b, &extra) != 2 ||
        a < INT32_MIN || a > INT32_MAX || b < INT32_MIN || b > INT32_MAX) {
        fputs(u8"輸入錯誤。請在同一行輸入兩個 32 位元整數。\n", stderr);
        return 1;
    }

    printf("%lld\n", lcm((int32_t)a, (int32_t)b));
    return 0;
}
