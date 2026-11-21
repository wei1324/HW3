#include <stdio.h>
#include "../console.h"

void hanoi(unsigned int disks, int from, int to, int spare)
{
    if (disks == 1) {
        printf("%d -> %d\n", from, to);
        return;
    }

    hanoi(disks - 1, from, spare, to);
    printf("%d -> %d\n", from, to);
    hanoi(disks - 1, spare, to, from);
}

int main(void)
{
    use_utf8_console();
    long long disks;
    char line[80], extra;
    // shortcut: 終端機最多顯示 32,767 步，若改用檔案儲存步驟，可提高上限。
    fputs(u8"請輸入圓盤數量（1 到 15，例如 3）：", stderr);
    fflush(stderr);
    if (!fgets(line, sizeof line, stdin) ||
        sscanf(line, "%11lld %c", &disks, &extra) != 1 || disks < 1 || disks > 15) {
        fputs(u8"輸入錯誤。請輸入 1 到 15 的整數。\n", stderr);
        return 1;
    }

    hanoi((unsigned int)disks, 1, 3, 2);
    return 0;
}
