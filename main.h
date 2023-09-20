#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);

/* FUNCTIONS */
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);
int handle_int(va_list args);
int handle_binary(va_list args);

#endif
