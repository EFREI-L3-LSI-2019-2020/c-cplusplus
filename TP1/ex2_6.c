#include <stdio.h>
#include <stdbool.h>

int factorial(int nb)
{
	int result = 1;

	for(int i = 2; i <= nb; i++)
	{
		result *= i;
	}

	return result;
}

int main()
{
	bool valid = false;
	int n, p, result;

	while(!valid)
	{
		printf("n/p : ");
		if(scanf("%d/%d", &n, &p) == 2)
		{
			if(n >= p)
			{
				result = factorial(n) / (factorial(p) * factorial(n - p));
				valid = true;
			}
		}

		fseek(stdin, 0, SEEK_CUR);
	}

	printf("Combinaisons : %d", result);

	return 0;
}