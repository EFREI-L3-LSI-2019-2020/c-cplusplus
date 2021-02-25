#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int nb, pow, result;
	bool valid = false;

	while(!valid)
	{
		printf("number^power : ");
		
		if(scanf("%d^%d", &nb, &pow) == 2)
		{
			result = nb;
			for(int i = 1; i < pow; i++)
			{
				result = result * pow;
			}

			valid = true;
		}

		fseek(stdin, 0, SEEK_END);
	}

	printf("%d^%d = %d", nb, pow, result);
}