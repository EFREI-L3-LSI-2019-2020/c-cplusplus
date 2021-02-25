#include <stdio.h>
#include <stdbool.h>

int main()
{
	int nb, result;
	bool valid = false;

	while(!valid)
	{
		printf("Factorial of : ");

		if(scanf("%d", &nb))
		{
			result = 1;

			for(int i = 2; i <= nb; i++)
			{
				result *= i;
			}

			valid = true;
		}
	}

	printf("Factorial of %d is %d", nb, result);

	return 0;
}