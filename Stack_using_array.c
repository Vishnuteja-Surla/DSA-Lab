#include<stdio.h>
#include<stdlib.h>

int top=-1;
int n;

int isempty(int *a)
{
    if(top==-1)
    {
        printf("Stack Empty\n");
        return(1);
    }
    else
    return(2);
}

int isfull(int *a)
{
    if(top==n-1)
    {
        printf("Stack full\n");
        return(1);
    }
    else
    return(2);
}

void push(int *a)
{
    int x;
    x=isfull(a);
    if(x==2)
    {
        top++;
        printf("Enter the value to be pushed : ");
        scanf("%d",&a[top]);
    }
}

void pop(int *a)
{
    int x;
    x=isempty(a);
    if(x==2)
    {
        top--;
    }
}

void displaystack(int *a)
{
    for(int i=0; i<=top; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void peek(int *a)
{
    printf("%d\n",a[top]);
}

int main()
{
    printf("Enter the size of the stack : ");
    scanf("%d",&n);
    int a[n];
    return(0);
}