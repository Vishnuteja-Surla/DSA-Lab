#include<stdio.h>

int front=-1, rear=-1, count=0;

void enqueue(int n, int *a)
{
    if(front==-1)
    {
        printf("Enter the element : ");
        scanf("%d",&a[0]);
        front=0; rear=0;
        count++;
    }
    else if(count==n)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear=(rear+1)%n;
        printf("Enter the element : ");
        scanf("%d",&a[rear]);
        count++;        
    }
}

void dequeue(int n, int *a)
{
    if(front==-1)
    {
        printf("Queue is Empty\n");
    }
    else if(front==rear)
    {
        front=-1; rear=-1;
        count--;
    }
    else
    {
        front=(front+1)%n;
        count--;
    }
}

void displayqueue(int n, int *a)
{
    int i=front;
    while(i!=rear)
    {
        printf("%d ",a[i]);
        i=(i+1)%n;
    }
    printf("%d\n",a[rear]);
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int a[n];
    return(0);
}