#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *head, int value)
{
    if(head==NULL)
    {
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->left=NULL;  newnode->right=NULL;
        head=newnode;
    }
    else if(value<=head->data)
    {
        head->left=insert(head->left,value);
    }
    else
    {
        head->right=insert(head->right,value);
    }
    return(head);
}

struct node *search(struct node *head, int value)
{
    if(head==NULL)
    {
        printf("Not found\n");
    }
    else if(head->data==value)
    {
        return(head);
    }
    else if(head->data>=value)
    {
        head->left=search(head->left,value);
    }
    else
    {
        head->right=search(head->right,value);
    }
}

struct node *successor(struct node *head)
{
    struct node *temp;
    temp=head->right;
    if(head->right!=NULL)
    {
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return(temp);
    }
}

struct node *predecessor(struct node *head)
{
    struct node *temp;
    temp=head->left;
    if(head->left==NULL)
    {
        printf("No Predecessor\n");
        return(head);
    }
    else
    {
        if(temp->right!=NULL)
        {
            return(temp->right);
        }
        else
        temp->left=predecessor(temp->left);
    }
}

struct node *delete(struct node *head,int value)
{
    if(head==NULL)
    {
        return(head);
    }
    else if(value>head->data)
    {
        head->right=delete(head->right,value);
    }
    else if(value<head->data)
    {
        head->left=delete(head->left,value);
    }
    else
    {
        struct node *temp;
        if(head->left==NULL)
        {
            temp=head->right;
            free(head);
            return(temp);
        }
        else if(head->right==NULL)
        {
            temp=head->left;
            free(head);
            return(temp);
        }
        else
        {
            temp=predecessor(head->right);
            head->data=temp->data;
            head->right=delete(head->right,temp->data);
        }
    }
}

void inorder(struct node *head)
{
    if(head==NULL)
    {
        return ;
    }
    else
    {
        inorder(head->left);
        printf("%d ",head->data);
        inorder(head->right);
    }
}

int main()
{
    struct node *root,*temp;
    root=NULL;
    int x;
    int ch=1,choice;
    while(ch==1)
    {
        printf("What do you want to perform? 1.Insert 2.Delete 3.Search 4.Print : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter the value to insert : ");
            scanf("%d",&x);
            root=insert(root,x);
        }
        else if(choice==2)
        {
            printf("Enter the value to be deleted : ");
            scanf("%d",&x);
            delete(root,x);
            inorder(root);
        }
        else if(choice==3)
        {
            printf("Enter the value to be searched : ");
            scanf("%d",&x);
            temp=search(root,x);
            printf("%d\n",temp->data);
        }
        else if(choice==4)
        {
            inorder(root);
            printf("\n");
        }
        else
        {
            printf("Enter a number from 1 to 4\n");
        }
        printf("Press 1 to operate again : ");
        scanf("%d",&ch);
    }
    return(0);
}