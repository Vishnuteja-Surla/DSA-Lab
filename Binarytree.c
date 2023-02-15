#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct queue
{
    int front, rear;
    struct node * *arr[50];
};

struct queue *createqueue()
{
    struct queue *q;
    q=(struct queue *)malloc(sizeof(struct queue));
    q->front=-1;  q->rear=-1;
    for(int i=0; i<50; i++)
    {
        q->arr[i]=NULL;
    }
    return(q);
}

void enqueue(struct queue *q, struct tree *root)
{
    q->rear=q->rear++;
    q->arr[q->rear]=root;
}

void dequeue(struct queue *q)
{
    struct node *temp;
    temp=q->arr[q->front];
    q->front=q->front++;
    return(temp);
}

struct tree *createnode(int data)
{
    struct tree *newnode;
    newnode=(struct tree *)malloc(sizeof(struct tree));
    newnode->data=data;
    newnode->left=NULL;  newnode->right=NULL;
    return(newnode);
}

void preorder(struct tree *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    else
    return ;
}

void inorder(struct tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    else
    return ;
}

void postorder(struct tree *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
    else
    return ;
}

struct tree *createtree(struct tree *root)
{
    if(root==NULL)
    {

    }
    else
    {

    }
}

int main()
{
    struct tree *root;
    root=createtree(root);
    return(0);
}