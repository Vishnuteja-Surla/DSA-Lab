#include<stdio.h>
#include<stdlib.h>

void maxheap(int a[], int j, int n)
{
    int largest,left,right;
    int temp;
    largest=j;
    left=2*j+1;     right=2*j+2;
    if(left>=n)
    return ;
    else
    {
        if(left<n && a[left]>a[j])
        {
            largest=left;
        }
        if(right<n && a[right]>a[largest])
        {
            largest=right;
        }
    }
    if(largest!=j)
    {
        temp=a[j];
        a[j]=a[largest];
        a[largest]=temp;
        maxheap(a,largest,n);
    }
}

void maxheapify(int a[], int n)
{
    for(int j=n/2-1; j>=0; j--)
    {
        maxheap(a,j,n);
    }
}

void heapsort(int a[],int n)
{
    int temp;
    maxheapify(a,n);
    for(int i=n-1; i>=0; i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        maxheapify(a,i);
    }
}

int main()
{
    int n;
    char ch;
    printf("Enter the number of nodes in the binary heap : ");
    scanf("%d",&n);
    int arr[n],m[n];
    printf("Enter the array elements : ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    maxheapify(arr,n);
    for(int i=0; i<n; i++)
    printf("%d ",arr[i]);
    printf("\n");
    heapsort(arr,n);
    for(int i=0; i<n; i++)
    printf("%d ",arr[i]);
    printf("\n");    
    return(0);
}