#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NB_CHAR 100

typedef struct 
{
	char *word;
	unsigned int count;
} Present;

void get_text(char *str);
void remove_special_char_tolower(char str[]);

#endif