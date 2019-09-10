#include "main.h"

int main()
{
	char *str = NULL;
	size_t size = 0;
	printf("Donnez un titre à votre message: ");
	getline(&str, &size, stdin);

	size_t ln = strlen(str) - 1;
	if (*str && str[ln] == '\n')
		str[ln] = '\0';

	Q_a_b(copystr(str));
	Q_c(copystr(str));

	//char str[1000] = "Une personne m'a dit le mot bonjour. J'ai répondu bonjour à cette personne! Bonjour? Quel joli mot!";
	return 0;
}

char *copystr(char str[])
{
	char *origin = malloc(strlen(str) * sizeof(char));
	strcpy(origin, str);
	return origin;
}
void get_text(char *str)
{
	size_t size = 0;
	printf("Donnez un titre à votre message: ");
	getline(&str, &size, stdin);	
}

void remove_special_char_tolower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		else if (str[i] == '.' || str[i] == '!' || str[i] == '?')
		{
			str[i] = ' ';
		}
	}
}

void affichage(Present freq[100], int ite)
{
	for (int i = 0; i < ite; i++)
	{
		printf("%s:%d\n", freq[i].word, freq[i].count);
	}
}

void Q_a_b(char str[])
{
	printf("************************\n");
	printf("*         Q_a_b        *\n");
	printf("************************\n");

	Present freq[100];
	remove_special_char_tolower(str);
	char *pch = strtok(str, " ");
	int ite = 0;
	while (pch != NULL)
	{
		int present = 0;
		for (int i = 0; i < ite; i++)
		{
			if (strcmp(freq[i].word, pch) == 0)
			{
				freq[i].count++;
				present = 1;
			}
		}

		if (present == 0)
		{
			freq[ite] = (Present){pch, 1};
			ite++;
		}

		pch = strtok(NULL, " ");
	}
	free(pch);
	free(str);

	affichage(freq, ite);
}

void Q_c(char str[])
{
	printf("************************\n");
	printf("*          Q_c         *\n");
	printf("************************\n");

	Present freq[100];
	remove_special_char_tolower(str);
	char *pch = strtok(str, " ");
	int ite = 0;
	while (pch != NULL)
	{
		int present = 0;
		for (int i = 0; i < ite; i++)
		{
			if (strcmp(freq[i].word, pch) == 0)
			{
				freq[i].count++;
				present = 1;
			}
		}

		if (present == 0)
		{
			freq[ite] = (Present){pch, 1};
			ite++;
		}

		pch = strtok(NULL, " ");
	}
	free(pch);
	free(str);

	affichage(freq, ite);
}