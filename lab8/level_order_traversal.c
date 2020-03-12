#include<stdio.h>
#include<stdlib.h>

typedef struct node* Nodeptr;
struct node
{
    int data;
    Nodeptr left, right;
};

Nodeptr queue[100];
int f = -1, r = -1;
void push(Nodeptr x)
{
    if(f == -1 && r == -1)
    {
        f = 0, r = 0;
        queue[r] = x;
    }
    else
    {
        queue[++r] = x;
    }
}

Nodeptr pop()
{
    if(f == r)
    {
        Nodeptr x = queue[r];
        f = -1, r = -1;
        return x;
    }
    else
    {
        return queue[f++];
    }
    
}

int isEmpty()
{
    if(f == -1 && r == -1){return 1;}
    else{return 0;}
}

Nodeptr create_node(int x)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

Nodeptr create_tree(Nodeptr root, int x)
{
    if(root == NULL)
    {
        Nodeptr temp = create_node(x);
        root = temp;
    }
    int a, b;
    printf("enter to the left of %d: \n", root->data);
    scanf(" %d", &a);
    if(a != -1){root->left = create_tree(root->left, a);}

    printf("enter to the right of %d: \n", root->data);
    scanf(" %d", &b);
    if(b != -1){root->right = create_tree(root->right, b);}

    return root;   
}

void preorder(Nodeptr root)
{
    if(root != NULL)
    {
        printf(" %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void level_order(Nodeptr root)
{
    printf("the level order traversal is: \n");

    if(root == NULL){return;}
    //push the root node into the queue
    push(root);
    while(f != -1 && r != -1)
    {
        Nodeptr temp = pop();
        printf(" %d", temp->data);
        if(temp->left){push(temp->left);}
        if(temp->right){push(temp->right);}
    }
}

int main()
{
    int a;
    Nodeptr root = NULL;
    printf("enter the root: \n");
    scanf(" %d", &a);

    printf("enter the elements, press -1 to exit: \n");
    root = create_tree(root, a);
    preorder(root);
    printf("\n");
    level_order(root);
}
