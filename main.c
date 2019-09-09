#include "main.h"

int main()
{
	char *str, *pch;
	get_text(&str);
	//char str[1000] = "Une  personne personne m'a  dit  le  mot  bonjour.  J'ai  répondu  bonjour  à  cette personne! Bonjour? Quel joli mot!";
	Present dico[100];

	pch = strtok(str, " ");
	int ite = 0;
	while (pch != NULL)
	{
		int present = 0;
		for (int i = 0; i < ite; i++)
		{
			if (strcmp(dico[i].word, pch) == 0)
			{
				dico[i].count++;
				present = 1;
			}
		}

		if (present == 0)
		{
			dico[ite] = (Present){pch, 1};
			ite++;
		}

		pch = strtok(NULL, " ");
	}
	free(pch);

	for (int i = 0; i < ite; i++)
	{
		printf("%s\t\t:%d\n", dico[i].word, dico[i].count);
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
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if ((str[i] >= 'A' && str[i] <= 'Z'))
                str[i] = str[i] + 32;
        }
        else
            str[i] = ' ';
    }
}