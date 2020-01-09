#include<stdio.h>
#include<stdlib.h>



typedef struct node *Nodeptr;

struct node 
{
	Nodeptr left;
	Nodeptr right;
	int data;
};

Nodeptr create_node()
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

/*
Nodeptr Create_Tree()
{

	Nodeptr temp = create_node();
	int ele;
	printf("enter a number (-1 for exit)\n");
	scanf("%d",&ele);
	if( ele == -1)
	{
		return NULL;
	}
	else
	{		
		temp->data = ele;
		printf("enter the element on right of %d \n",temp->data );
		temp->right = Create_Tree();
		printf("enter the element on left of %d \n",temp->data );
		temp->left = Create_Tree();
		
	}
	return temp;
}
*/
/*
Nodeptr Create_Tree(Nodeptr root)
{
	int ele;
	printf("enter a number \n");\
	scanf("%d", ele);

	Nodeptr newnode = create_node();
	newnode->data = ele;
	newnode->right = NULL;
	newnode->left = NULL;

	if(root == NULL)
	{
		root = newnode;
		return root;
	}
	else
	{
		while(1)
		{

		}
	}

}
*/

void Search(Nodeptr root)
{
	if(root == NULL)
	{
		printf("tree is empty \n");
		return;
	}
	int key;
	printf("enter the key to be Searched \n");
	scanf("%d", &key);
	Nodeptr newnode = create_node();
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;

	Nodeptr temp = root;
	while(1)
	{
		if(key > temp->data)
		{
			temp = temp->right;
		}
		else if(key < temp->data)
		{
			temp = temp->left;
		}
		else if(key == temp->data)
		{
			printf("key found \n");
			return;
		}

		if(temp->right == NULL && temp->left == NULL)
		{
			if(temp->data < key)
			{
				temp->right = newnode;
				printf("new node added to right of %d \n", temp->data);
				return;
			}
			else if(temp->data > key)
			{
				temp->left = newnode;
				printf("new node added to left of %d \n", temp->data);
				return;
			}
		}
	}




}


void preorder(Nodeptr root)
{
	if(root != NULL)
	{	
		printf("%d \t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Nodeptr root)
{
	if(root != NULL)
	{	
		inorder(root->left);
		printf("%d \t", root->data);
		inorder(root->right);
	}
}

void postorder(Nodeptr root)
{
	if(root != NULL)
	{	
		postorder(root->left);
		postorder(root->right);
		printf("%d \t", root->data);
	}
}

int main()
{
	Nodeptr root = NULL;
	root = Create_Tree();
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	Search(root);
	inorder(root);
	printf("\n");


}