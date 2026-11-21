#include <stdio.h>
#include "../console.h"
#include <string.h>

int main(void)
{
    use_utf8_console();
    const char string1[] = "Welcome";
    char string2[sizeof string1];

    strcpy(string2, string1);
    printf(u8"複製後的字串：%s\n", string2);
    printf(u8"字串長度：%zu\n", strlen(string2));
    return 0;
}
