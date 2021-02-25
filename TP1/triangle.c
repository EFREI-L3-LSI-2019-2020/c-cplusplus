#include <stdio.h>
#include <string.h>

#define N 4

void generate()
{
	int triangle[N + 1][N + 1];

	memset(triangle, 0, sizeof(triangle));

	for(int i = 0; i <= N; i++)
	{
		triangle[i][i] = 1;
		triangle[i][0] = 1;

		for(int j = 1; j < i; j++)
		{
			triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
		}
	}
	
	for (int i = 0; i <= N; i++)
    { 
        for (int j = 0; j <= N; j++) 
        {
			if(triangle[i][j])
				printf("%d ", triangle[i][j]); 
		}
        printf("\n"); 
    } 
}

int main()
{
	generate();

	return 0;
}