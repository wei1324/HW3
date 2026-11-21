#include <math.h>
#include <stdio.h>

int main(void)
{
    for (int x = 1; x <= 10; ++x) {
        printf("%.2f%c", sqrt(x), x == 10 ? '\n' : ' ');
    }
    return 0;
}
