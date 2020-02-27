#include<stdio.h>
#include<stdlib.h>

int queue[100];
int f = 0, r = -1;
void push(int x){queue[++r]= x;}
int pop(){return queue[f++];}

typedef struct node *Nodeptr;
struct node
{
	int data;
	Nodeptr left, right;
};

Nodeptr create_node(int x)
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	temp->data = x;
	temp->left = temp->right = NULL;
}

Nodeptr create_heap(Nodeptr root, int ele)
{
	if(root == NULL)
	{
		push(ele);
		Nodeptr temp = create_node(ele);
		root = temp;
	}
	else
	{
		if(root->data < ele && root->left == NULL)
		{
			root->left = create_heap(root->left, data);
		}
		else if(root->data < ele && root->right == NULL)
		{
			root->right = create_heap(root->right, data);			
		}
		else
		{
			
		}
	}
	
}




int main()
{
	int arr[100];

	return 0;
}