#include <stdio.h>
#include "../console.h"
#include <stdlib.h>
#include <time.h>

static int roll_dice(void)
{
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    int sum = die1 + die2;
    printf(u8"玩家擲出 %d + %d = %d\n", die1, die2, sum);
    return sum;
}

int main(void)
{
    use_utf8_console();
    srand((unsigned int)time(NULL));
    int sum = roll_dice();
    int won;

    switch (sum) {
        case 7:
        case 11:
            won = 1;
            break;
        case 2:
        case 3:
        case 12:
            won = 0;
            break;
        default: {
            int point = sum;
            printf(u8"目標點數為 %d\n", point);
            do {
                sum = roll_dice();
            } while (sum != point && sum != 7);
            won = sum == point;
            break;
        }
    }

    puts(won ? u8"玩家獲勝" : u8"玩家落敗");
    return 0;
}
