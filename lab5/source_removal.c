#include<stdio.h>
#include<stdlib.h>

int mat[100][100];
int s,v,e;

void addEdge(int x, int y)
{
    mat[x][y] = 1;
    
}

void Display(int v)
{
    for(int i = 1; i <= v; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}


void source(int s)
{
	int flag = 0;
	for(int i = 1; i <= v; i++)
	{
		if(mat[i][s] != 0)
		{
			flag = 1;
		}
	}
	if(flag == 0)
	{
		for(int i = 1; i <= v; i++)
		{
			mat[s][i] = 0;
		}
		printf("%d  ",s);
	}
	
}

void fun()
{	
	for(int i = 1; i <= v; i++)
	{
		source(i);
	}
}


int main()
{
	int v1, v2;
    printf("enter no. of vertices and edges: \n");
    scanf("%d %d", &v, &e);

    printf("enter the pairs: \n");
    int count = e;
    while(count > 0)
    {
        scanf("%d %d", &v1, &v2);
        addEdge(v1, v2);
        count -= 1;
    }

    Display(v);

    fun();
}