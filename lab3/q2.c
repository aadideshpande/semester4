#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int opcount=0;
	char* str1 = (char *)calloc(1000, sizeof(char));
	char* str2 = (char *)calloc(1000, sizeof(char));

	printf("enter main and  substring the strings \n");
	scanf(" %s %s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	/*for(int i = 0; i <= len1 - len2; i++)
	{
		for(int j = 0; j < len2; j++)
		{
			opcount++;
			if(str2[j] != str1[i + j] )
			{
				break;
			}
			if(j == len2 - 1)
			{
				printf("found at position %d \n",i+1 );
				break;
			}
		}
	}
	printf("opcount is %d \n", opcount);
	*/

	for(int i = 0; i <= len1 - len2; i++)
	{
		int j = 0;
		opcount++;
		while(j < len2 && str1[i + j] == str2[j])
		{
			opcount++;
			j++;
		}
		
		if(j == len2 )
		{
			printf("found at position %d opcount is %d  \n", i +1,opcount);
		}
	}
	printf("opcount is %d \n",opcount );		
}