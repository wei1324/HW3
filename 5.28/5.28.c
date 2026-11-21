#include <ctype.h>
#include <stdio.h>
#include "../console.h"

int change_case(unsigned char letter)
{
    if (islower(letter)) {
        return toupper(letter);
    }
    return tolower(letter);
}

int main(void)
{
    use_utf8_console();
    char line[80], letter, extra;
    fputs(u8"請輸入一個英文字母（A–Z 或 a–z），再按 Enter：", stderr);
    fflush(stderr);
    if (!fgets(line, sizeof line, stdin) ||
        sscanf(line, " %c %c", &letter, &extra) != 1 ||
        !isalpha((unsigned char)letter)) {
        fputs(u8"輸入錯誤。請只輸入一個英文字母，例如 Z。\n", stderr);
        return 1;
    }

    printf("%c\n", change_case((unsigned char)letter));
    return 0;
}
