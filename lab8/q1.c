// top down heap using trees

#include<stdio.h>
#include<stdlib.h>

typedef struct node* Nodeptr;
struct node
{
	int data;
	Nodeptr rchild, lchild, par;
};

typedef struct
{
	Nodeptr arr[100];
	int f, r;
}Q;

void add(Q *q, Nodeptr num)
{
	if(q->r == 100){printf("queue is full \n");}
	else{q->arr[(q->r)++] = num;}
}

Nodeptr del(Q *q)
{
	if(q->f > q->r){printf("queue is empty \n");}
	else{return q->arr[(q->f)++];}
}

Q* init()
{
	Q* myq  = (Q*)malloc(sizeof(Q));
	myq->r = 0;
	myq->f = 0;
}

Nodeptr getnode(int n)
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	temp->data = n;
	temp->rchild = temp->lchild = temp->par = NULL;
	return temp;
}

void inorder(Nodeptr root)
{
	if(root!= NULL)
	{
		inorder(root->lchild);
		printf("%d ",root->data);
		inorder(root->rchild);
	}
}

Nodeptr insert(Nodeptr root, int n)
{
	Nodeptr newnode = getnode(n);
	if(!root)
	{
		newnode->par = NULL;
		return newnode;
	}
	Nodeptr curr = NULL, p = NULL;
	Q* q  = init();
	add(q, root);
	while(1)
	{
		curr = del(q);
		if(curr->lchild){add(q, curr->lchild);}
		if(curr->rchild){add(q, curr->rchild);}
		else{break;}
	}
	newnode->par = curr;
	if(curr->lchild){curr->lchild = newnode;}
	else{curr->lchild = newnode;}
	p = curr;
	curr = newnode;
	while(p && p->data < curr->data)
	{
		int t = p->data;
		p->data = curr->data;
		curr->data = t;
		curr = p;
		p->par = p;
	}
	return root;
}

void main()
{
	Nodeptr root = NULL;
	int n;
	printf("enter the elements: \n");
	scanf(" %d", &n);
	while(n != -1)
	{
		root = insert(root, n);
		scanf(" %d", &n);
	}
	printf("heap inorder: \n");
	inorder(root);
	printf("\n");
}