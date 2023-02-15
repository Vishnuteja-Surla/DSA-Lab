#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createlist()
{
    printf("Enter the length of the list : ");
    int n;
    scanf("%d",&n);
    struct node *head, *temp;
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            head=(struct node *)malloc(sizeof(struct node));
            printf("Enter data : ");
            scanf("%d",&head->data);
            head->next=NULL;
            temp=head;
        }
        else
        {
            temp->next=(struct node *)malloc(sizeof(struct node));
            printf("Enter data : ");
            scanf("%d",&temp->next->data);
            temp=temp->next;
            temp->next=NULL;
        }
    }
    return(head);
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct node *insert(struct node *head)
{
    int k;
    printf("Enter the position you want insert at : ");
    scanf("%d",&k);
    struct node *temp,*newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(k>1)
    {
        int i=1;
        while(i<k-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    
    return(head);
}

struct node *delete(struct node *head)
{
    int k;
    printf("Enter the position to be deleted : ");
    scanf("%d",&k);
    struct node *temp,*p;
    temp=head;
    if(k>1)
    {
        for(int i=1; i<k-1; i++)
        {
            temp=temp->next;
        }
        p=temp->next;
        temp->next=temp->next->next;
        free(p);
    }
    else
    {
        head=head->next;
        free(temp);
    }
    return(head);
}

void reverselist(struct node *head)
{
    struct node *temp=head;
    struct node *prev,*next;
    prev=NULL;
    while(head!=NULL)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    head=prev;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct node *swap(struct node *head)
{
    int a,b;
    printf("Enter the values to be swapped : ");
    scanf("%d%d",&a,&b);
    struct node *temp,*p1,*p2,*last,*dummy,*dummy2,*dummy3;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    last=temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==a||temp->data==b)
        {
            p1=temp;
            break;
        }
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        if(temp->next->data==a||temp->next->data==b)
        {
            p2=temp->next;
            break;
        }
        temp=temp->next;
    }
    if(temp->data==a&&temp->next->data!=b)
    {
        temp=temp->next;
        if(p1->data==head->data)
        {
            if(p2->data==last->data)
            {
                temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            p2->next=head->next;
            p1->next=NULL;
            temp->next=p1;
            head=p2;
            last=p1;
        }
        else
        {
            dummy=p2->next;
            p2->next=p1->next;
            temp->next=p1;
            p1->next=dummy;
            head=p2;
        }
    }
    else if(p2->data==last->data)
    {
        dummy=head;
        while(dummy->next->data!=p1->data)
        {
            dummy=dummy->next;
        }
        dummy2=dummy->next->next;
        dummy->next=p2;
        p2->next=dummy2;
        temp->next=p1;
        p1->next=NULL;
        last=p1;
    }
    else
    {
        dummy=head;
        while(dummy->next->data!=p1->data)
        {
            dummy=dummy->next;
        }
        dummy2=dummy->next->next;
        dummy3=temp->next->next;
        dummy->next=p2;
        p2->next=dummy2;
        temp->next=p1;
        p1->next=dummy3;
    }
    }
    else
    {
        dummy=head;
        while(dummy->next->data!=a)
        {
            dummy=dummy->next;
        }
        dummy2=temp->next->next;
        dummy->next=p2;
        p2->next=p1;
        p1->next=dummy2;
    }
    
    return(head);
}

int main()
{
    struct node *head;
    head=createlist();
    display(head);
    head=insert(head);
    display(head);
    head=delete(head);
    display(head);
    reverselist(head);
    head=swap(head);
    display(head);
    return(0);
}