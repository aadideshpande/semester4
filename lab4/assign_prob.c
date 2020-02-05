#include<stdio.h>
#include<stdlib.h>

int main()
{
    int p,j;
    //int v1, v2;
    printf("enter no. of people and jobs: \n");
    scanf("%d %d", &p, &j);

    int** mat = (int **)malloc( (p + 1) * sizeof(int *));
    for(int i = 1; i < p + 1; i++)
    {
        mat[i] = (int *)calloc( (j + 1),sizeof(int));
    }

    int* person = (int *)calloc(p + 1, sizeof(int));
    // < j1, j2, j3,....jn > 
    // p1 gets j1 job, p2 gets j2 job and so on...
    //  
    

    
}