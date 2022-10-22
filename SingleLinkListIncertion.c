// single link-list -- for incertion only -- add at begin -- add at location -- add at end 
#include <stdio.h>
#include<stdlib.h>

void append(void);
void addatbegin(void);
void search(void);
int length(void);
void display(void);
void delete(void);
void addAtLoc(void);


struct node 
{
    int data;
    struct node* link ;
};
struct node* root = NULL;
int len;


void main()
{
    int ca;

    while (1)
    {
        printf("\nEnter | 1 - Add at Begining | 2 - Add At Location  | 3 - App At End | 4 - Delete | 5 - Display | 0 - Exit | Single link list - Incertion");
        printf("\nEnter your choice - ");
        scanf("%d",&ca);
        switch (ca)
        {
        case 1:
            addatbegin();
            break;
        
        case 2:
            addAtLoc();
            break;

        case 3:
            append();
            break;

        case 4:
            delete();
            break;

        case 5:
            display();
            break;

        case 0:
            exit(1);
            break;

        default: printf("Invalid input");
            break;
        }
    }
}

void append()
{
    struct node* temp ;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data - ");
    scanf("%d",&temp->data);
    temp->link= NULL;

    if (root == NULL) // if the link-list is empty
    {
        root = temp;
    }
    else
    {
        struct node* p;
        p = root;
        while ((p->link !=NULL))
        {
            p = p->link;
        }
        p->link = temp;
    }
    display();
}

void search()
{
    int count = 0;
    int find ;
    int found=0;

    struct node* temp;
    temp = root;
    printf("Enter the number to find - ");
    scanf("%d",&find);

    while (temp!= NULL)
    {
        count++;
        if(temp->data==find)
        {
            printf("The element found at - %d\n",count);
            found++;
        }
        temp=temp->link;
    } 
    if (found==0)
    {
        printf("The element not found\n");
    }
}

void display()
{
    struct node* temp;
    temp=root;
    if (temp==NULL)
    {
        printf("Link-List is Empty");
    } 
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp= temp->link;
        }
        printf("\n");
    }

}

void addatbegin(void)
{
    struct node* temp;
    temp= (struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data : ");
    scanf("%d",&temp->data);
    temp->link  = NULL;

    if ( root== NULL)
    {
        root = temp;
    }
    else
    {
        temp-> link = root ;
        root = temp;
    }
    display();
}

void delete()
{
    struct node* temp;
    int dloc;
    struct node* p = root;
    struct node* q;
    int i = 1;
    printf("Enter Location to delete : ");
    scanf("%d",&dloc);

    if(dloc>length())
    {
        printf("Location Not Found");
    }
    else if (dloc == 1) // node is at first location
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        while (i<dloc-1)
        {
            p = p->link; 
            i++;
        }
        q = p->link; 
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
    display();
}

int length()
{
    int count = 0;
    struct node* temp;
    temp = root;

    while (temp!= NULL)
    {
        count++;
        temp=temp->link;
    } 
    return count;
}

void addAtLoc()
{
    struct node* temp;
    // newnode = (struct node*)malloc(sizeof(struct node));
    temp = (struct node*)malloc(sizeof(struct node));
    int loc;
    struct node* r = root;
    struct node* newnode;
    int i = 1;

    printf("Enter Location to Add at : ");
    scanf("%d",&loc);

    temp->link= NULL;

    if(loc>length())
    {
        printf("Location Not Found");
    }
    else
    {
        temp=root;
        while (i<loc-1)
        {
            temp=temp->link;
            r = r->link; 
            i++;
        }
        printf("Enter node data - ");
        scanf("%d",&newnode->data);
        newnode->link = temp->link;
       temp->link=newnode;
    }
    display();
}