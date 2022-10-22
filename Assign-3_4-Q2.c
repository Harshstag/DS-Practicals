// Asignment 3&4 Q2 - 
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    char data;
    struct node *link;

};
struct node *dummy = NULL;
struct node *root1 = NULL;

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
            printf("%d-->",temp->data);
            temp=temp->link;
        }
    }
    printf("\n\n");
}


struct node* create(struct node* root1, struct node* dummy, int n2)
{
    struct node* temp1 = root1;
    struct node* temp2 = dummy;
    int i = 0;
    while (temp2 != NULL && i<n2)
    {
        struct node *newnode = ((struct node*)malloc(sizeof(struct node)));

        newnode->data = temp2->data;
        newnode->link = NULL;

        if (root1 == NULL)
        {
            root1 = newnode;
            temp1 = root1;
        }
        else
        {
            while (temp1->link != NULL)
            {
                temp1 = temp1->link;
            }
            temp1->link = newnode;
        }
        temp2 = temp2->link;
        i++;
    }
    while (i < n2)
    {
        int data;
        printf("Enter the node data : ");
        scanf("%d", &data);

        struct node* newnode=((struct node*)malloc(sizeof(struct node)));
        
        newnode->data = data;
        newnode->link = NULL;

        if (temp1 == NULL)
        {
            root1 = newnode;
            temp1 = root1;
        }
        else
        {
            while (temp1->link != NULL)
            {
                temp1 = temp1->link;
            }
            temp1->link = newnode;
        }
        i++;
    }
    return root1;
}

struct node* createdummy(struct node* dummy, int n)
{
    struct node* temp= dummy;
    for(int i=1;i<= n;i++)
    {
        int data;

        printf("Enter data for node %d  :  ",i);
        scanf("\n%d",&data);

        struct node* newnode=((struct node*)malloc(sizeof(struct node)));

        newnode->data=data;
        newnode->link=NULL;

        if(dummy==NULL)
        {
            dummy=newnode;
            temp = dummy;
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
    display(dummy);
    return dummy;
}


int main()
{
    int n,n2;

    printf("\nEnter the length of Dummy link-list : ");
    scanf("%d",&n);

    dummy=createdummy(dummy,n);
    

    printf("\nEnter the length of new link-list : ");
    scanf("%d",&n2);

    root1=create(root1,dummy,n2);

    printf("\nThe new linked-list is : ");
    display(root1);
}
