#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int knapsack( int* w, int *v, int n, int B)
{
	int index,temp;
	int max_weight, max_value;
	int MAX = 0;
	int max_seq;
	for(int i = 1; i < pow(2,n); i++)
	{
		max_weight = 0;
		max_value = 0;
		temp = i;
		index = 0;
		while(temp)
		{
			if(temp & 0x1)
			{
				max_weight += w[index];
				max_value += v[index];
			}
			index++;
			temp >> 1;
		}

		if(max_weight <= B && max_value > MAX)
		{
			//printf("here \n");
			MAX = max_value;
			max_seq = i;
		}
	}
	return max_seq;
}



int main()
{
	int n, b;
	int my_weight=0, my_value=0;
	printf("enter the number of values \n");
	scanf(" %d", &n);
	int* w = (int *)calloc(n, sizeof(int));
	int* v = (int *)calloc(n, sizeof(int));
	printf("enter the max weight of the backpack \n");
	scanf("%d", &b);

	printf("enter the weights \n");
	for(int i = 1; i <= n; i++)
	{
		scanf(" %d", &w[i]);
	}

	printf("enter the values \n");
	for(int i = 1; i <= n; i++)
	{
		scanf(" %d", &v[i]);
	}

	int knap = knapsack(w, v, n, b);
	int i = 0;
	while(knap)
	{
		if(knap & 0x1)
		{
			my_weight += w[i];
			my_value += v[i];

		}
	}
	printf("the weight is %d \n", my_weight );
	printf("the value is %d \n", my_value );
}