#include "main.h"

int main()
{
	char *str, *pch;
	size_t size = 0;
	printf("Donnez un titre à votre message: ");
	getline(&str, &size, stdin);

	size_t ln = strlen(str) - 1;
	if (*str && str[ln] == '\n')
		str[ln] = '\0';
		
	//char str[1000] = "Une personne m'a dit le mot bonjour. J'ai répondu bonjour à cette personne! Bonjour? Quel joli mot!";
	Present freq[100];
	remove_special_char_tolower(str);
	pch = strtok(str, " ");
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

	for (int i = 0; i < ite; i++)
	{
		if (freq[i].word == NULL)
		{
			printf("nylkl");
		}
		printf("%d:%s:%d\n", i, freq[i].word, freq[i].count);
	}

	return 0;
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