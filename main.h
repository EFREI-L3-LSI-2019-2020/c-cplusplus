#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
	char *word;
	unsigned int count;
	double freq;
} Present;

typedef struct
{
	Present *present;
	unsigned int length;
} PresentList;

PresentList *Q_a_b(char[]);
void Q_c(char[], char[], PresentList *);
void Q_d(PresentList *);
void Q_e(PresentList *);

char *copystr(char[]);
void remove_special_char_tolower(char[]);
void affichage(Present[], int);
void affichageList(PresentList *);
void triBulle(PresentList *);

#endif