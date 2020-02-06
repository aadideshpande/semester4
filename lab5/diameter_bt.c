#include<stdio.h>
#include<stdlib.h>

typedef struct node* Nodeptr;
struct node
{
	int data;
	Nodeptr left, right;
};

Nodeptr newnode()
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int max(int x, int y)
{
	return (x > y)?x:y;
}

int height(Nodeptr node)
{
	if(node == 0){return 0;}
	else
	{
		return (1 + max(height(node->right), height(node->left)));
	}
}



Nodeptr create_tree(Nodeptr root,int x)
{
	printf("enter -1 to quit: \n");
	int l,r;
	if(x == -1){return NULL;}
	if(root == NULL)
	{
		root = newnode();
		root->data = x;
	}
	
	printf("enter the left node of %d \n", root->data);
	scanf(" %d", &l);
	root->left = create_tree(root->left, l);

	printf("enter the right node of %d \n", root->data);
	scanf(" %d", &r);
	root->right = create_tree(root->right, r);
	
}
void preorder(Nodeptr root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int diameter(Nodeptr root)
{
	if(root == NULL){return 0;}
	int lh = height(root->left);
	int rh = height(root->right);

	int ld = height(root->left);
	int rd = height(root->right);

	return 	max(lh+rh+1, max(ld, rd));
}



int main()
{
	int num;
	Nodeptr root = NULL;
	printf("enter the root value: \n");
	scanf("%d", &num);
	root = create_tree(root, num);
	preorder(root);
	printf("\n");
	printf("diameter is: %d \n", diameter(root));
}