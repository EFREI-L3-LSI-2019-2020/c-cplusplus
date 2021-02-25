#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int nb;
	int min = 0;
	int max = 4;
	bool valid = false;

	while (!valid)
	{
		printf("Enter a number beetween 0 & 4 : ");
		long res = scanf("%d", &nb);

		if (res)
		{
			if (nb >= min || nb <= max)
				valid = true;
		}

		fseek(stdin, 0, SEEK_END);
	}

	printf("Valid number !\n");

	return 0;
}