#include <limits.h>
#include <stdio.h>
#include "../console.h"

int maximum(int x, int y, int z)
{
    int max = x;
    if (y > max) {
        max = y;
    }
    if (z > max) {
        max = z;
    }
    return max;
}

int main(void)
{
    use_utf8_console();
    long long x, y, z;
    char line[80], extra;
    fputs(u8"請輸入三個整數，以空格分隔（例如 22 85 17）：", stderr);
    fflush(stderr);
    if (!fgets(line, sizeof line, stdin) ||
        sscanf(line, "%11lld%*1[ \t] %11lld%*1[ \t] %11lld %c", &x, &y, &z, &extra) != 3 ||
        x < INT_MIN || x > INT_MAX || y < INT_MIN || y > INT_MAX ||
        z < INT_MIN || z > INT_MAX) {
        fputs(u8"輸入錯誤。請在同一行輸入三個 int 範圍內的整數。\n", stderr);
        return 1;
    }

    printf(u8"最大值為 %d\n", maximum((int)x, (int)y, (int)z));
    return 0;
}
