#include<stdio.h>
#include<stdlib.h>

void copy(int a[],int s1, int e1, int b[], int s2, int e2)
{
	for(int i = s1; i <= e1; i++)
	{
		b[i] = a[i];		
	}
}

void merge(in
	t b[], int c[], int a[])
{
	int i = 0, j = 0;;
	while(i )
}


int* mergesort(int n, int a[])
{
	int b[100], int c[100];
	if(n > 1)
	{
		int floor = int(n/2);
		copy(a, 0, floor-1, b, 0, floor-1);
		copy(a, floor, n-1, c, 0, floor-1);
		mergesort(floor,b);
		mergesort(floor,c);
		merge(b,floor, c, floor,a, n);
	}
	return a;
}


int main()
{
	int n, x;
	int arr[100];
	printf("enter number of elements in the array: \n");
	scanf(" %d", &n);

	printf("enter the array elements: \n");
	for(int i = 0; i < n; i++)
	{
		scanf(" %d", &x);
		arr[i] = x;
	}
	arr = mergesort(n, arr);
}