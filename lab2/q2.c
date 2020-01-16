#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* prime_factor(int n)
{
	int j, count  = 0;
	int *array = (int *)malloc(n * sizeof(int));
	int *l = (int *)malloc(n * sizeof(int));
	for(int i = 2; i <= n; i++ )
	{
		array[i] = i;
		//printf("%d \n", array[i] );
	}
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(array[i] != 0)
		{
			j = i * i;
			while(j <= n)
			{
				array[j] = 0;
				count++;
				j = j + i;
			}
		}
	}


	int i = 0;
	for(int p = 2; p <= n; p++)
	{
		if(array[p] != 0)
		{
			l[i] = array[p];
			//printf("%d \t ", l[i] );
			i += 1;
		}
	}
	printf("\n");


	return l;
}

int* prime_count()
{

}

int main()
{
	int n, m;
	printf("enter numbers whose pf are to be calculated \n");
	scanf("%d %d", &n, &m);
	//now, arrays a and b contain a list of all prime numbers
	// till the respective number itself
	int* a = prime_factor(n);
	int* b = prime_factor(m);
	int new_n = n;
	int new_m = m;
	int* count1 = (int *)calloc(n, sizeof(int));
	int* count2 = (int *)calloc(m, sizeof(int));


	// find a list of all the prime factors

			
		int i = 0;
		while(n != 1)
		{
				while( n % a[i] == 0)
				{

					n = n / a[i];
					//printf("%d \n", a[i] );
					count1[a[i]]++;
				}
				i++;
		}

		int j = 0;
		while(m != 1)
		{
				while( m % b[j] == 0)
				{

					m= m / b[j];
					//printf("counted %d \n", b[j] );
					count2[b[j]]++;
				}
				j++;
		}
		int gcd = 1;
		/*
		for(int i = 2; i < new_n ;i++)
		{
			printf("the no. of %d is %d \n",i, count1[i]);
		}
		for(int i = 2; i < new_m ;i++)
		{
			printf("the no. of %d is %d \n",i, count2[i]);
		}
	*/

		for(int i = 2 ; i < fmin(new_m,new_n); i++)
		{	
			//printf("here \n");
			if( count1[i] != 0 && count2[i] != 0)
			{
				int x = fmin(count1[i], count2[i]);
				//printf("x is %d \n", x );
				gcd  = gcd * x * i;
			}
		}	
		printf("gcd is %d \n", gcd );
}