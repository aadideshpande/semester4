#include<stdio.h>
#include<stdlib.h>

int mini(int x, int y)
{
	if(x > y)
	{
		return y;
	}
	else
	{
		return x;
	}
}

int main()
{
	int x, y;
	int opcount = 0;
	printf("enter two numbers to find gcd \n");
	scanf("%d %d", &x, &y);
	int min = mini(x,y);
	int t = min;
	while(t > 0)
	{
		opcount++;
		if(x % t == 0)
		{
			if(y % t == 0)
			{
				printf("gcd is %d \n", t);
				break;
			}
		}		
		t = t - 1;
	
	}
	printf("opcount is %d \n", opcount );

	

}