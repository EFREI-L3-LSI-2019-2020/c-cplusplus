#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	unsigned int hour, minute, second;
	bool valid = false;

	while(!valid)
	{
		printf("Enter a date in the format hh/mm/ss : ");

		if(scanf("%d:%d:%d", &hour, &minute, &second) == 3)
		{
			if(hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
			{
				valid = true;
			}
		}

		fseek(stdin, 0, SEEK_END);
	}

	printf("Your date is valid !");

	return 0;
}