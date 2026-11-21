#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include "../console.h"

double Power(double x, int n)
{
    double result = 1.0;
    for (int i = 0; i < n; ++i) {
        if (fabs(x) > 1.0 && fabs(result) > DBL_MAX / fabs(x)) {
            return HUGE_VAL;
        }
        result *= x;
    }
    return result;
}

int main(void)
{
    use_utf8_console();
    const double base = 3.5;
    long long n;
    char line[80], extra;
    fputs(u8"計算 3.5 的次方。請輸入非負整數指數（例如 5）：", stderr);
    fflush(stderr);
    if (!fgets(line, sizeof line, stdin) ||
        sscanf(line, "%11lld %c", &n, &extra) != 1 || n < 0 || n > INT_MAX) {
        fputs(u8"輸入錯誤。指數須為非負整數且在 int 範圍內。\n", stderr);
        return 1;
    }

    double result = Power(base, (int)n);
    if (!isfinite(result)) {
        fputs(u8"結果超出 double 可表示的範圍。\n", stderr);
        return 1;
    }
    printf("%.1f^%lld = %.6f\n", base, n, result);
    return 0;
}
