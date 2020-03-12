#include<stdio.h>
#include<stdlib.h>

typedef struct node* Nodeptr;
struct node
{
	int str[100];
	Nodeptr next;
};



int main()
{
	int n;
	printf("enter the number of strings: \n");
	scanf(" %d", &n);

	Nodeptr* arr = (Nodeptr*)malloc((n + 1) * sizeof(Nodeptr));

	for(int i = 0; i <= n; i++)
	{
		arr[i]->str = '0';
		arr[i]->next = NULL;
	}
	

	/*
	char** mat = (char**)malloc((n + 1) * sizeof(char*));

	printf("enter the strings: \n");
	for(int i =0; i < n; i++)
	{
		mat[i] = (char*)malloc(100 * sizeof(char));
		scanf(" %s", mat[i]);
	}

	printf("the strings are: \n");
	for(int i = 0; i < n; i++)
	{
		printf("%s \n", mat[i]);
	}
	*/
}