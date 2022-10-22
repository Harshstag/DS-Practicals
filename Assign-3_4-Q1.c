// Asignment 3&4 Q1 - 
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    char data;
    struct node *link;

};

struct node* root1 = NULL;
struct node* root2 = NULL;


void display(struct node* root){
    struct node* temp;
    temp = root;
    if(temp==NULL)
    {
        printf("\nLink-list is empty");
    }
    else{
        while (temp!=NULL)
        {
            printf("%c-->",temp->data);
            temp=temp->link;
        }
    }
    printf("\n\n");
}




struct node* create(struct node* root)
{

    int n;
    printf("\nEnter number of nodes you want : ");
    scanf("%d",&n);

    struct node* temp=root;
    for(int i=1;i<=n;i++)
    {
        char ch;
        printf("Enter %d Node Data :  ", i);
        scanf("\n%c",&ch);
        struct node* newnode= ((struct node*)malloc(sizeof(struct node)));
        newnode->data=ch;
        newnode->link=NULL;
        if(root==NULL)
        {
            root=newnode;
            temp=root;
        }
        else
        {
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=newnode;
        }
    }
    display(root);
    return root;
}

struct node* merge(struct node* root1,struct node* root2)
{
    if (root2 ==NULL)
    {
        return root1;
    }
    else
    {
        struct node *temp1 = root1;
        struct node *temp2 = root2;
    
        for (int i = 1; i <= 4; i++)
        {
            while(temp1->link != NULL)
            {
                temp1=temp1->link;
            }
            if (temp2->link==NULL)
            {
                temp1->link=temp2;
            }
            else
            {
                while(temp2->link->link != NULL)
                {
                    temp2=temp2->link;
                }
                temp1->link=temp2->link;
                temp2->link=NULL;
                temp2 = root2;
            }
        }
    }
    return root1;
}


int main()
{

    printf("\nEnter the Elements of 1st Linked Listc");
    root1 = create(root1);
    printf("\nEnter the Elements of 2nd Linked List\n");
    root2 = create(root2);

    root1 = merge(root1, root2);
    display(root1);

    return 0;
}