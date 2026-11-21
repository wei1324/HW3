#ifndef HW3_CONSOLE_H
#define HW3_CONSOLE_H

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

static UINT original_output_code_page;

static void restore_output_code_page(void)
{
    fflush(NULL);
    SetConsoleOutputCP(original_output_code_page);
}

static void use_utf8_console(void)
{
    original_output_code_page = GetConsoleOutputCP();
    if (original_output_code_page != 0 && original_output_code_page != CP_UTF8 &&
        atexit(restore_output_code_page) == 0) {
        SetConsoleOutputCP(CP_UTF8);
    }
}
#else
static void use_utf8_console(void)
{
}
#endif

#endif
