//stack using single linklist
#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* link ;
};
struct node* top = NULL;

void push(void);
void pop(void);
void traverse(void);

void main()
{
    int ca;
    while (1)
    {
        printf("\nEnter | 1 - Push | 2 -Pop | 3 - Traverse | 4 - Exit | Stack Using Link-List ");
        printf("\nEnter your choice - ");
        scanf("%d",&ca);
        switch (ca)
        {
        case 1:
            push();
            break;
        
        case 2:
            pop();
            break;

        case 3:
            traverse();
            break;

        case 4:
            exit(1);
            break;

        default: printf("Invalid input");
            break;
        }
    }
}
void push()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct  node));
    printf("Enter Node data ");
    scanf("%d",&temp->data);
    temp->link = top; 
    top = temp;  
}

void pop()
{
    struct node* temp;

    if(top==NULL)
    {
        printf("No node is present stack is empty \n");
    }
    else
    {
        temp=top;
        printf("Poped element is %d\n",temp->data);
        top =top->link;
        temp->link = NULL;
        free(temp);
    }  
}

void traverse()
{
    struct node* temp;
    if(top==NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        temp=top;
        printf("Top-> \t");
        while (temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }  
        printf("\n");
    }
}