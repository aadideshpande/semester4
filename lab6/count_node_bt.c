#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

typedef struct node *Nodeptr;
struct node
{
	int data;
	Nodeptr left, right;
};

Nodeptr create_node(int mydata)
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	temp->data = mydata;
	temp->left = temp->right = NULL;
	return temp;
}

Nodeptr create_tree(Nodeptr root, int x)
{
	if(x == -1){return NULL;}

	int ip;
	Nodeptr temp = create_node(x);
	if(root == NULL)
	{
		root = temp;
	}
		printf("enter till -1 not encountered: \n");

			printf("enter element to the left of %d: \n", root->data);
			scanf(" %d", &ip);
			root->left = create_tree(root->left, ip);

			printf("enter element to the right of %d: \n", root->data);
			scanf(" %d", &ip);
			root->right = create_tree(root->right, ip);

		return root;
}

int counter(Nodeptr root)
{
	opcount++;
	static int count = 0;
	if(root == NULL){return 0;}
	else
	{
		count++;
		counter(root->left);
		counter(root->right);

	}
	return count;
}

int main()
{
	Nodeptr root = NULL;
	int root_num;
	printf("enter the root number: \n");
	scanf(" %d", &root_num);
	root = create_tree(root,root_num);
	int x = counter(root);
	printf("no. of nodes is: %d \n", x );

	printf("opcount is: %d \n", opcount);
}