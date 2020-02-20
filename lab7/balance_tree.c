// find the balance factor of all the nodes is a BST
#include<stdio.h>
#include<stdlib.h>

typedef struct node *Nodeptr;
struct node
{
	int data;
	Nodeptr left, right;
};

int max(int a, int b)
{
	return ((a > b)?a:b);
}

int height(Nodeptr root)
{
	if(root == NULL){return 0;}
	else
	{
		return (1 + max(height(root->right), height(root->left)));
	}
}

/*
Nodeptr finder(Nodeptr root, int y)
{
	Nodeptr myptr = NULL;
	if(root == NULL)
	{
		printf("number not found \n");
	}
	else if (y < root->data)
	{
		myptr = finder(root->left, y);
	}
	else if (y >root->data)
	{
		myptr = finder(root->right, y);
	}
	if(y ==root->data){myptr = root;}
	return myptr;	

}
*/
Nodeptr create(Nodeptr root, int x)
{
	if(root == NULL)
	{
		Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
		temp->data = x;
		temp->left = temp->right = NULL;
		root = temp;
	}
	else if(x > root->data)
	{
		root->right = create(root->right, x);
	}
	else if(x < root->data)
	{
		root->left = create(root->left, x);
	}
	else
	{
		printf("duplicates \n");
	}
	return root;
}

void inorder(Nodeptr root)
{
	if(root != NULL)
	{
		
		inorder(root->left);
		printf("%d \t", root->data);
		printf("the balance factor of %d is: %d \n" ,root->data,height(root->left) - height(root->right));
		inorder(root->right);
	}
}

int main()
{
	int y;
	Nodeptr root = NULL;
	int num;
	printf("enter number ( -1 to quit) \n");
	scanf(" %d", &num);
	while(num != -1)
	{
		root = create(root, num);
		printf("enter another option: \n");
		scanf(" %d", &num);
	}
	inorder(root);
	//printf("\n enter node whose balance factor we have to find: \n");
	//scanf("%d", &y);
	//Nodeptr ptr_y = finder(root, y);
	//printf("value of finder function is %d \n", ptr_y->data);
	//printf("the balance factor is: %d \n" ,height(ptr_y->left) - height(ptr_y->right));

}