#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,temp;
	long opcount= 0;
	printf("enter number of elements in the array: \n");
	scanf("%d", &n);
	int* arr = (int *)calloc(n, sizeof(int));

	for(int i = 0; i < n ; i++)
	{
		arr[i] = rand() % 1000;	
	}

	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			opcount++;
			if(arr[j + 1] < arr[j])
			{
				//printf("swapping \n");
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	/*for(int i = 0; i < n ; i++)
	{
		printf(" %d \t  ", arr[i]);
	}*/
	printf("\n opcount is %ld \n  ",opcount);
}