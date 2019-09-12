#include "main.h"

/* TODO
	- Better secure entry
 */

int main()
{
	char *str = NULL;
	size_t size = 0;
	printf("Donnez un titre à votre message: ");
	getline(&str, &size, stdin);

	size_t ln = strlen(str) - 1;
	if (*str && str[ln] == '\n')
		str[ln] = '\0';

	remove_special_char_tolower(str);
	WordList *list = Q_a_b(copystr(str));
	Q_c(copystr(str), "le", list);
	Q_d(list);
	Q_e(list);

	freeWordList(list);
	free(str);

	return 0;
}

WordList *Q_a_b(char str[])
{
	printf("************************\n");
	printf("*         Q_a_b        *\n");
	printf("************************\n");

	Word *words = (Word *)calloc(0, sizeof(Word));
	char *pch = strtok(str, " ");
	int ite = 0;

	while (pch != NULL)
	{
		int present = 1;
		for (int i = 0; i < ite; i++)
		{
			if (strcmp(words[i].str, pch) == 0)
			{
				words[i].count++;
				present = 0;
			}
		}

		if (present)
		{
			char *word = (char *)calloc(strlen(pch), sizeof(char));
			strcpy(word, pch);

			words = (Word *)realloc(words, (ite + 1) * sizeof(Word));
			words[ite] = (Word){word, 1, 0};
			ite++;
		}

		pch = strtok(NULL, " ");
	}
	free(pch);
	free(str);

	affichage(words, ite);

	WordList *list = (WordList *)calloc(1, sizeof(WordList));
	list->words = words;
	list->length = ite;
	list->wordLength = 0;

	return list;
}

void Q_c(char str[], char search[], WordList *list)
{
	printf("************************\n");
	printf("*          Q_c         *\n");
	printf("************************\n");

	Word *dico = (Word *)calloc(1, sizeof(char));
	int ite = 0;

	for (int i = 0; i < list->length; i++)
	{
		int new = 0;
		if (list->words[i].count > 1)
		{
			for (int j = 0; j < ite; j++)
			{
				if (strcmp(dico[j].str, list->words[i].str) == 0)
				{
					new = 1;
				}
			}

			if (new == 0)
			{
				dico = (Word *)realloc(dico, (ite + 1) * sizeof(Word));

				Word present = list->words[i];
				char *string = (char *)calloc(strlen(present.str), sizeof(char));
				strcpy(string, present.str);
				present.str = string;

				dico[ite] = present;
				ite++;
			}
		}
	}

	char *result = (char *)calloc(0, sizeof(char));
	char *pch = strtok(str, " ");

	while (pch != NULL)
	{
		unsigned long size = strlen(pch);
		char temp[size - 1];
		strcpy(temp, pch);

		for (int i = 0; i < ite; i++)
		{
			if (strcmp(pch, dico[i].str) == 0)
			{
				for (int j = 0; j < size; j++)
				{
					temp[j] = '#';
				}
			}
		}
		strcat(temp, " ");
		result = (char *)realloc(result, (strlen(result) + strlen(temp) + 1) * sizeof(char));
		strcat(result, temp);

		pch = strtok(NULL, " ");
	}

	affichage(dico, ite);
	printf("%s\n", result);

	free(result);
	freeWordArray(dico, ite);
	free(pch);
	free(str);
}

void Q_d(WordList *list)
{
	printf("************************\n");
	printf("*          Q_d         *\n");
	printf("************************\n");

	for (int i = 0; i < list->length; i++)
	{
		list->wordLength += list->words[i].count;
	}

	for (int i = 0; i < list->length; i++)
	{
		double freq = (double)list->words[i].count / (double)list->wordLength;
		list->words[i].freq = freq;
	}

	affichageList(list);
}

void Q_e(WordList *list)
{
	printf("************************\n");
	printf("*          Q_e         *\n");
	printf("************************\n");

	triBulle(list);
}

char *copystr(char str[])
{
	char *origin = (char *)calloc(strlen(str), sizeof(char));
	strcpy(origin, str);
	return origin;
}

void remove_special_char_tolower(char str[])
{
	//Dire quelle est secure
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		else if (str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == '-' || str[i] == ',')
		{
			str[i] = ' ';
		}
	}
}

void affichage(Word *words, int ite)
{
	for (int i = 0; i < ite; i++)
	{
		printf("%s\t:%d\n", words[i].str, words[i].count);
	}
}

void affichageList(WordList *list)
{
	for (int i = 0; i < list->length; i++)
	{
		printf("%s : %lf\n", list->words[i].str, list->words[i].freq);
	}
}

void triBulle(WordList *list)
{
	for (int j = 1; j <= list->length; j++)
	{
		for (int i = 0; i < list->length - 1; i++)
		{
			if (list->words[i].count < list->words[i + 1].count)
			{
				Word word = list->words[i];
				list->words[i] = list->words[i + 1];
				list->words[i + 1] = word;
			}
		}
	}
	affichageList(list);
}

void freeWordList(WordList *list)
{
	freeWordArray(list->words, list->length);
	free(list);
}

void freeWordArray(Word *word, int length)
{
	for (int i = 0; i < length; i++)
	{
		free(word[i].str);
	}

	free(word);
}