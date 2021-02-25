#include <stdio.h>

int main()
{
	int j, m, a;

	printf("Entrez une date avec le format jour/mois/annee \n");
	scanf("%d/%d/%d", &j, &m, &a);

	if(m == 1 || m == 2)
	{
		m += 12;
		a -= 1;
	}

	if(a < 1582)
	{
		printf("L'annee doit etre superieur a 1582\n");
		return 0;
	}

	int s = a / 100;

	int JD = 1720996.5 - s + (int)(s / 4) + (int)(365.25 * a) + (int)(30.6001 * (m + 1)) + j;
	JD = JD - (int)(JD / 7) * 7;

	printf("Le jour est un ");

	switch(JD % 7)
	{
		case 0: printf("mardi"); break;
		case 1: printf("mercredi"); break;
		case 2: printf("jeudi"); break;
		case 3: printf("vendredi"); break;
		case 4: printf("samedi"); break;
		case 5: printf("dimanche"); break;
		case 6: printf("lundi"); break;
	}

	printf(".\n");

	return 0;
}