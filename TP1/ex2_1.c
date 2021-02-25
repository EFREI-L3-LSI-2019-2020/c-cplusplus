#include <stdio.h>

int main()
{
	printf("This is a question ?");

	int nb;

	scanf("%d", &nb);


	if(nb == 1)
	{
		printf("Good answer :)");
	}
	else
	{
		printf("Bad answer :(");
	}

	return 0;
}