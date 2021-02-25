#include <stdio.h>

int main()
{
	printf("Enter a year : ");

	int year;

	scanf("%d", &year);

	if(year % 4 == 0)
	{
		if(year % 100 == 0 || year % 400 != 0)
		{
			printf("This is not a leap year");

			return 0;
		}

		printf("This is a leap year");
	}

	return 0;
}