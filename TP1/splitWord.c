#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
	char **list;
	unsigned int length;
}wordList;

void onlyLetter(char * string)
{
	for(int i = 0; i < strlen(string); i++)
	{
		if((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z'))
		{
			if(string[i] >= 'A' && string[i] <= 'Z') string[i] += 32;
		}
		else string[i] = ' ';
	}
}

wordList splitWord(char *string, const char delimiter)
{
	unsigned int count = 0;
	char **args = NULL;
	char *s = strtok(string, &delimiter);

	while(s != NULL)
	{
		bool new = true;

		if(s != NULL)
		{
			for(int i = 0; i < count; i++)
			{
				if(strcmp(s, args[i]) == 0) new = false;
			}

			if(new)
			{
				if(count == 0) args = (char**)malloc(1 * sizeof(char *));
				else args = realloc(args, (count + 1) * sizeof(char *));

				args[count] = (char *)malloc(sizeof(s) * sizeof(char *));
				strcpy(args[count], s);
				count++;
			}
		}

		s = strtok(NULL, &delimiter);
	}

	free(s);

	wordList list = {args, count};

	return list;
}

int main()
{
	char *str = NULL;
	size_t size = 0;

	printf("Enter a message : ");
	getline(&str, &size, stdin);

	onlyLetter(str);
	wordList words = splitWord(str, ' ');

	printf("Size : %d\n", words.length);

	for(int i = 0; i < words.length; i++)
	{
		printf("word %d : %s\n", i, words.list[i]);
	}

	return 0;
}