#include<stdio.h>
#include<stdlib.h>

typedef struct node *Nodeptr;

struct node
{
	int data;
	Nodeptr next;
};

Nodeptr createnode()
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

void AddEdge(Nodeptr* table, int x, int y)
{
	Nodeptr temp = createnode();
	temp->data = y;

	//table[i] = 
}



int main()
{
	int v;
	printf("enter the number of rows \n");
	scanf("%d", &v);
	//Nodeptr* table = (Nodeptr*)calloc(v + 1 ,sizeof(Nodeptr));
	while(option != -1)
	{
		printf("enter the two vertices that have a link \n");
		int x, y;
		scanf(" %d %d", &x, &y );
		Nodeptr List[v];


























































		
		//AddEdge(table, x, y);

		printf("do you want to add another link  1 = yes , -1 = no\n");
		scanf(" %d", &option);

	}

}