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

#endif
