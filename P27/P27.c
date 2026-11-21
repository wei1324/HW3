#include <stdio.h>

long factorial(long number)
{
    if (number <= 1) {
        return 1;
    }
    return number * factorial(number - 1);
}

int main(void)
{
    for (int i = 0; i <= 10; ++i) {
        printf("%2d! = %ld\n", i, factorial(i));
    }
    return 0;
}
