#include <stdio.h>
#include <string.h>

#define N 3

void tor(int *x, int *y)
{
	if(*x < 0)
		*x = N - 1;

	if(*x >= N)
		*x = 0;

	if(*y < 0)
		*y = N - 1;

	if(*y >= N)
		*y = 0;
}

void generate()
{
	int square[N][N];

	memset(square, 0, sizeof(square));

	int x = N / 2 - 1;
	int y = N / 2;

	square[x][y] = 1;
  
    for (int i = 2; i <= N * N; i++)
    {
		x--;
		y++;

		tor(&x, &y);

		if(square[x][y])
		{
			x--;
			y--;
			
			tor(&x, &y);
		}
		
		square[x][y] = i;
    }

	for (int i=0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf("%3d ", square[i][j]); 
        printf("\n"); 
    } 
}

int main()
{
	generate();

	return 0;
}