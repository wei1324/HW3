#include <stdio.h>

int square(int y)
{
    return y * y;
}

int main(void)
{
    for (int x = 1; x <= 10; ++x) {
        printf("%d%c", square(x), x == 10 ? '\n' : ' ');
    }
    return 0;
}
