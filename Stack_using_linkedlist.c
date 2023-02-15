#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int a)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=top;
    top=newnode;
}

int pop()
{
    int x=isempty();
    if(x==1)
    return(0);
    else
    {
        struct node *temp;
        temp=top;
        top=top->next;
        int value;
        value=temp->data;
        free(temp);
        return(value);
    }
}

int isempty()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return(1);
    }
    else
    return(2);
}

void peek()
{
    printf("%d\n",top->data);
}

void display()
{
    int n;
    n=size(top);
    int a[n];
    struct node *temp;
    temp=top;
    for(int i=n-1; i>=0; i--)
    {
        a[i]=temp->data;
        temp=temp->next;
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int size()
{
    struct node *temp;
    temp=top;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return(count);
}


int main()
{
    int n;
    printf("Enter the size of the stack : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter data : ");
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {
        push(a[i]);
    }
    return(0);
}