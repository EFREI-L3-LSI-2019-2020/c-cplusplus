#include "main.h"

int main()
{
	char *str = NULL;
	size_t size = 0;
	printf("Donnez un titre à votre message: ");
	getline(&str, &size, stdin);
	//char str[1000] = "le magasin ouvrira le 12 juin et le 14 juin.";

	size_t ln = strlen(str) - 1;
	if (*str && str[ln] == '\n')
		str[ln] = '\0';

	remove_special_char_tolower(str);
	PresentList *list = Q_a_b(copystr(str));
	Q_c(copystr(str), "le", list);
	Q_d(list);
	Q_e(list);

	free(list);
	free(str);

	return 0;
}

PresentList* Q_a_b(char str[])
{
	printf("************************\n");
	printf("*         Q_a_b        *\n");
	printf("************************\n");

	Present *freq = (Present *)calloc(0, sizeof(Present));
	char *pch = strtok(str, " ");
	int ite = 0;
	while (pch != NULL)
	{
		int present = 1;
		for (int i = 0; i < ite; i++)
		{
			if (strcmp(freq[i].word, pch) == 0)
			{
				freq[i].count++;
				present = 0;
			}
		}

		if (present)
		{
			char *word = (char *)calloc(strlen(pch), sizeof(char));
			strcpy(word, pch);

			freq = (Present *)realloc(freq, (ite + 1) * sizeof(Present));
			freq[ite] = (Present){word, 1, 0};
			ite++;
		}

		pch = strtok(NULL, " ");
	}
	free(pch);
	free(str);

	affichage(freq, ite);

	PresentList *list = (PresentList*) calloc(1, sizeof(PresentList));
	list->present = freq;
	list->length = ite;

	return list;
}

void Q_c(char str[], char search[], PresentList *list)
{
	printf("************************\n");
	printf("*          Q_c         *\n");
	printf("************************\n");

	Present *dico = NULL;
	int ite = 0;

	for (int i = 0; i < list->length; i++)
	{
		int new = 0;
		if (list->present[i].count > 1)
		{
			for (int j = 0; j < ite; j++)
			{
				if (strcmp(dico[j].word, list->present[i].word) == 0)
				{
					new = 1;
				}
			}

			if (new == 0)
			{
				dico = (Present *)realloc(dico, (ite + 1) * sizeof(Present));
				dico[ite] = list->present[i];
				ite++;
			}
		}
	}

	char *result = (char *)calloc(0, sizeof(char));
	char *pch = strtok(str, " ");

	while (pch != NULL)
	{
		int size = strlen(pch);
		char temp[size];
		strcpy(temp, pch);

		for (int i = 0; i < ite; i++)
		{
			if (strcmp(pch, dico[i].word) == 0)
			{
				for (int j = 0; j < size; j++)
				{
					temp[j] = '#';
				}
			}
		}
		strcat(temp, " ");
		result = (char *)realloc(result, (strlen(result) + strlen(temp)) * sizeof(char));
		strcat(result, temp);

		pch = strtok(NULL, " ");
	}

	affichage(dico, ite);
	printf("%s\n", result);

	free(result);
	free(dico);
	free(pch);
	free(str);
}

void Q_d(PresentList *list)
{
	printf("************************\n");
	printf("*          Q_d         *\n");
	printf("************************\n");

	int total = 0;

	for (int i = 0; i < list->length; i++)
	{
		total += list->present[i].count;
	}

	for (int i = 0; i < list->length; i++)
	{
		double freq = (double) list->present[i].count / (double) total;
		list->present[i].freq = freq;
	}

	affichageList(list);
	//triBulle(list);
}

void Q_e(PresentList *list)
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

void affichage(Present *freq, int ite)
{
	for (int i = 0; i < ite; i++)
	{
		printf("%s:%d\n", freq[i].word, freq[i].count);
	}
}

void affichageList(PresentList *list)
{
	for (int i = 0; i < list->length; i++)
	{
		printf("%s : %lf\n", list->present[i].word, list->present[i].freq);
	}
}

void triBulle(PresentList *list)
{
	for (int j = 1; j <= list->length; j++) // pour faire l'operation N fois
	{
		for (int i = 0; i < list->length - 1; i++)
		{
			if (list->present[i].count < list->present[i + 1].count)
			{
				Present present = list->present[i];
				list->present[i] = list->present[i + 1];
				list->present[i + 1] = present;
			}
		}
	}
	affichageList(list);
}