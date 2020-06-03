#include<stdio.h>
#include<stdlib.h>


void heapTopDown(int* arr, int n, int index)
{
	int r_child, l_child, mx_child;
	for(int i = index; i <= 2 * index; i++)
	{
		l_child = 2 * index; // the left child
		r_child = l_child + 1;
		mx_child;

		
		// the node has no left child means it is a leaf node
		if(l_child > n)
		{
			return;
		}
		if(l_child < n)	// there are two children
		{
			mx_child = arr[l_child] > arr[r_child] ? l_child : r_child;
		}
		else{mx_child = l_child;}
		if(arr[mx_child] > arr[index]) // if the child is greater than the parent, then swap them
		{
			int temp = arr[mx_child];
			arr[mx_child] = arr[index];
			arr[index] = temp;
		}
		heapTopDown(arr, n, l_child);
		heapTopDown(arr, n, r_child);
	}




}

int main()
{
	int n;
	printf("enter the number of elements: \n");
	scanf("%d", &n);
	int* arr = (int*)malloc(1000 * sizeof(int));
	printf("enter the elements: \n");
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	heapTopDown(arr, n, 1);
	for(int i = 1; i <= n; i++)
	{
		printf("%d \t", arr[i]);
	}




	return 0;
}