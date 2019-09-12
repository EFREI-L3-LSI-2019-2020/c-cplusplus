#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
	char *str;
	unsigned int count;
	double freq;
} Word;

typedef struct
{
	Word *words;
	unsigned int length; //sans doublons
	unsigned int wordLength; //avec
} WordList;

WordList *Q_a_b(char[]);
void Q_c(char[], char[], WordList *);
void Q_d(WordList *);
void Q_e(WordList *);

char *copystr(char[]);
void remove_special_char_tolower(char[]);
void affichage(Word[], int);
void affichageList(WordList *);
void triBulle(WordList *);

void freeWordList(WordList *);
void freeWordArray(Word *, int);

#endif