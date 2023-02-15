#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data;
    struct node *next;
};

struct node *top=NULL;

void push(char a)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=top;
    top=newnode;
}

int empty()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return(1);
    }
    else
    return(2);
}

char pop()
{
    int x=empty();
    if(x==1)
    return(0);
    else
    {
        struct node *temp;
        temp=top;
        top=top->next;
        char value;
        value=temp->data;
        free(temp);
        return(value);
    }
}

void peek()
{
    printf("%c\n",top->data);
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

int precedence(char a)
{
    if(top==NULL)
    return(0);
    else if(a=='(')
    return(1);
    else if(a=='+'||a=='-')
    return(2);
    else if(a=='*'||a=='/')
    return(3);
}

void InfixtoPostfix(char *infix, int n)
{
    if(infix[0]!='(')
    {
        push('(');
        infix[n]=')';
        n=n+1;
    }
    int x,y;
    char postfix[n];
    int count=0;
    char waste;
    for(int i=0; i<n; i++)
    {
        if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
        {
            if(top!=NULL)
            {
                x=precedence(top->data);
                y=precedence(infix[i]);
                while(x>=y)
                {
                    postfix[count]=pop();
                    count++;
                    x=precedence(top->data);
                }
            }
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(top->data!='(')
            {
                postfix[count]=pop();
                count++;
            }
            waste=pop();
        }
        else
        {
            postfix[count]=infix[i];
            count++;
        }
    }
    while(top!=NULL)
    {
        postfix[count]=pop();
        count++;
    }
    printf("%s\n",postfix);
}

int main()
{
    char infix[30];
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    int n=strlen(infix);
    InfixtoPostfix(infix,n);
    return(0);
}