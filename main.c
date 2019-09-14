#include "main.h"

int main()
{
	bool select = true;
	unsigned int mode;

	while(select) //selection du menu
	{
		printf("Selectionnez un mode : \n");
		printf("1) Lire entrée clavier\n");
		printf("2) Lire fichier \"file.txt\"\n");

		fflush(stdin);

		if(scanf("%d", &mode) == 1)
		{
			switch (mode)
			{
				case 1:
					readInput();
					select = false;
					break;
				case 2:
					readFile();
					select = false;
					break;
				default: break;
			}
		}

		if(select)
		{
			char c;
			do {
				c = getchar();
			} while (c != '\n' && c != EOF);
		}
	}

	printf("\nEnd of program...\n");

	return 0;
}

void readInput()
{
	// fix EOF on windows
	char c;
	do {
        c = getchar();
    } while (c != '\n');

	printf("\nEntrez votre message : ");
	char *str = getInput();

	process(str);

	free(str);
}

void readFile()
{
	FILE *file = fopen("file.txt", "r");
	
	if(file == NULL)
	{
		printf("Error when reading the file \"file.txt\"");
		return;
	}

	char *str;

	while((str = getFileInput(file)) != NULL) process(str);

	free(file);
	free(str);
}

void process(char *str)
{
	size_t ln = strlen(str) - 1; //Remove last char(entrer) when user input
	if (*str && str[ln] == '\n') 
		str[ln] = '\0';

	remove_special_char_tolower(str);
	WordList *list = Q_a_b(copystr(str));
	Q_c(copystr(str), list);
	Q_d(list);
	Q_e(list);

	freeWordList(list);
}

WordList *Q_a_b(char str[])
{
	/* str to Wordlist structure */
	printf("************************\n");
	printf("*     Question_a_b     *\n");
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

	printf("Affichage des mots avec leur nombre d'ocurrence :\n");
	display(words, ite);

	WordList *list = (WordList *)calloc(1, sizeof(WordList));
	list->words = words;
	list->length = ite;
	list->wordLength = 0;

	return list;
}

void Q_c(char str[], WordList *list)
{
	printf("************************\n");
	printf("*      Question_c      *\n");
	printf("************************\n");

	Word *dico = (Word *)calloc(0, sizeof(char));
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
		char *temp = (char *)calloc(strlen(pch + 1), sizeof(char));
		strcpy(temp, pch);

		for (int i = 0; i < ite; i++)
		{
			if (strcmp(pch, dico[i].str) == 0) //if the word is not unique
			{
				for (int j = 0; j < size; j++) //remplace him by '#' (number of # depend off word lengh)
				{
					temp[j] = '#'; 
				}
			}
		}
		strcat(temp, " ");
		result = (char *)realloc(result, (strlen(result) + strlen(temp) + 1) * sizeof(char));
		strcat(result, temp);

		pch = strtok(NULL, " ");

		free(temp);
	}

	printf("Affichage du dictionnaire des mots supprimés :\n");
	display(dico, ite);

	printf("Affichage de la phrase modifiée :\n");
	printf("%s\n", result);

	free(result);
	freeWordArray(dico, ite);
	free(pch);
	free(str);
}

void Q_d(WordList *list)
{
	// Words frequency 
	printf("************************\n");
	printf("*      Question_d      *\n");
	printf("************************\n");

	for (int i = 0; i < list->length; i++)
	{
		list->wordLength += list->words[i].count; //Number words in a sentence 
	}

	for (int i = 0; i < list->length; i++)
	{
		double freq = (double)list->words[i].count / (double)list->wordLength; //Calculation of frenquency
		list->words[i].freq = freq; //affectation of the frequency in the word's structure
	}

	printf("Affichage de la liste des mots avec leurs fréquences :\n");
	displayList(list);
}

void Q_e(WordList *list)
{
	printf("************************\n");
	printf("*      Question_e      *\n");
	printf("************************\n");

	triBulle(list);
}

char *getFileInput(FILE *file)
{
	int c;
	size_t bufferSize = 16;
	size_t allocated = bufferSize;
	char *str = (char *)calloc(allocated, sizeof(char));
	unsigned int size = 0;

	while((c = getc(file)) != '\n' && c != EOF && c != 13)
	{
		if(size + 2 <= bufferSize)
		{
			allocated += bufferSize;
			char *newStr = (char *)realloc(str, allocated);

			if(!newStr)
			{
				free(str);
				return NULL;
			}

			str = newStr;
		}

		str[size++] = c;
	}

	if(file != stdin)
	{
		c = getc(file);
	}

	if(c == EOF && size == 0) return NULL;

	str[size] = 0;

	return str;
}

char *getInput()
{
	return getFileInput(stdin);
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
		if ((str[i] >= 'A' && str[i] <= 'Z')) //if the ascii code is between 'A' and 'Z'
			str[i] = str[i] + 32; //add 32(the difference between upper and lower case in the ascii table)
		else if (str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == '-' || str[i] == ',') //Remove special char
		{
			str[i] = ' ';
		}
	}
}

void display(Word *words, int ite)
{
	for (int i = 0; i < ite; i++)
	{
		printf("%s\t:%d\n", words[i].str, words[i].count);
	}
}

void displayList(WordList *list)
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
	displayList(list);
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