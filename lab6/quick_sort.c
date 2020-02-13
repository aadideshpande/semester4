#include<stdio.h>
#include<stdlib.h>


void swap(int *a, int x,int  y)
{
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int partition(int *a, int l, int r)
{
	int p = a[l];
	int i = l;
	int j = r + 1;
	do
	{
		do
		{
			i += 1;
		}while(a[i] < p);

		do
		{
			j -= 1;
		}while(a[j] > p);
		swap(a, i, j);

	}while(i < j);

	swap(a, i, j);
	swap(a, l, j);
	return j;
}

int* quicksort(int a[], int l, int  r)
{
	if(l < r)
	{
		int s = partition(a, l , r);
		a = quicksort(a, l ,s-1);
		a = quicksort(a, s+1, r);
	}
	return a;
}



int main()
{
	int n, x;
	int l, r;
	int arr[100];
	printf("enter number of elements in the array: \n");
	scanf(" %d", &n);

	printf("enter the array elements: \n");
	for(int i = 0; i < n; i++)
	{
		scanf(" %d", &x);
		arr[i] = x;
	}
	arr = quicksort(arr, l, r);

	printf("printing the final array: \n");
	for(int i = 0; i < n; i++)
	{
		printf(" %d  ", arr[i] );
	}	
	printf("\n");
}