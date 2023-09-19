#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);



/* FUNCTIONS */
int print_char(char c);
int print_string(char *str);
int print_percent(char c);
int print_int(int num);
int print_binary(unsigned int num);

#endif
