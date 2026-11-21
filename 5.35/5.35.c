#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include "../console.h"

unsigned long long int fibonacci(unsigned int n)
{
    if (n == 0) {
        return 0;
    }

    unsigned long long int previous = 0;
    unsigned long long int current = 1;
    for (unsigned int i = 1; i < n; ++i) {
        if (previous > ULLONG_MAX - current) {
            errno = ERANGE;
            return 0;
        }
        unsigned long long int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

int main(void)
{
    use_utf8_console();
    long long n;
    char line[80], extra;
    fputs(u8"請輸入費波那契數列的項次（從 0 開始，例如 10）：", stderr);
    fflush(stderr);
    if (!fgets(line, sizeof line, stdin) ||
        sscanf(line, "%11lld %c", &n, &extra) != 1 || n < 0 || n > UINT_MAX) {
        fputs(u8"輸入錯誤。項次須為非負整數且在 unsigned int 範圍內。\n", stderr);
        return 1;
    }

    errno = 0;
    unsigned long long int result = fibonacci((unsigned int)n);
    int result_overflowed = errno == ERANGE;

    errno = 0;
    unsigned int max_index = 0;
    unsigned long long int max_value = 0;
    while (1) {
        unsigned long long int next = fibonacci(max_index + 1);
        if (errno == ERANGE) {
            break;
        }
        ++max_index;
        max_value = next;
    }

    if (result_overflowed) {
        printf(u8"F(%lld) 超出 ULLONG_MAX。\n", n);
    } else {
        printf("F(%lld) = %llu\n", n, result);
    }
    printf(u8"可表示的最大項：F(%u) = %llu\n", max_index, max_value);
    return result_overflowed ? 1 : 0;
}
