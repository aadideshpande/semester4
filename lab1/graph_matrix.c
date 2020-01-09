#include<stdio.h>
#include<stdlib.h>

int main()
{
	int v;
	printf("enter the number of vertices \n");
	scanf("%d", &v);
	int** table = (int**)calloc(v +1 ,sizeof(int *));

	for(int i = 1; i <= v; i++)
	{
		table[i] = (int *)calloc(v + 1, sizeof(int));
	}

	int option = 0;
	while(option != -1)
	{
		printf("enter the two vertice numbers that have a link \n");
		int x, y;
		scanf(" %d %d", &x, &y );
		table[x][y] = 1;

		printf("do you want to add another link  1 = yes , -1 = no\n");
		scanf(" %d", &option);

	}

	for(int i = 1; i <= v; i++)
	{
		for(int j = 1; j <= v; j++)
		{
			printf("%d \t", table[i][j] );
		}
		printf("\n");
	}

	return 0;
}