#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* heapBottomUp(int* arr, int n)
{
	for(int i = floor(n / 2); i >= 1; i--)
	{
		int curr_ele = arr[i];
		int curr_pos = i;
		bool heap = false;
		while(!heap && 2 * curr_pos <= n) 
		{
		    int j = 2 * curr_pos; 	// the left node of the current node
		    if(j < n)				// this means that the node has two children and we have to find the max child node
		    {	
		    	if(arr[j] < arr[j + 1]){j = j + 1;}// j points to the max element from the children 
		    }
		    if(curr_ele >= arr[j])	// if parent node is > than both children
		    {
		    	heap = true;
		    }
		    else
		    {
		    	arr[curr_pos] = arr[j];	// child > parent, hence interchange
		    	curr_pos = j;
		    }
		}
		arr[curr_pos] = curr_ele; 
	}
	return arr;
}


int main()
{
	int* arr = (int*)malloc(1000 * sizeof(int));
	int n;
	printf("enter the number of elements: \n");
	scanf("%d", &n);
	printf("enter the elements: \n");
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	arr = heapBottomUp(arr, n);
	for(int i = 1; i <= n; i++)
	{
		printf("%d \t", arr[i]);
	}

	return 0;
}