#include<stdio.h>
#include<stdlib.h>
int len;
struct node {
    int data;
    struct node *next;

};
struct node *root = NULL;


void append(){

    int numofnode;
    printf("Enter Number of Node you want : ");
    scanf("%d", &numofnode);
    for (int i = 0; i < numofnode; i++)
    {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter Node Data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else{
        struct node *p;
        p = root;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    }

     
}
void avg(){

    struct node *temp;
    int total=0, avg;
    int i = 0;
    temp = root;
    while (temp != NULL)
    {
        i++;
        total = total + (temp->data);
        temp = temp->next; //++
    }

    avg = total / i;
    printf("The Average is : %d", avg);
    len = i;
}

void Display(){

    struct node *temp;
    temp = root;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next; //++
    }
}
void addAtLoc(){

    struct node *temp;
    int loc;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter The Location : ");
    scanf("%d", &loc);
    printf("\nEnter Node Data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else{
        if (len<loc)
        {
            struct node *p;
            p = root;
            struct node *q;

            for (int i = 0; i < loc; i++)
            {

                p = p->next;
                q = (p->next);

                p->next = temp;
                temp->next = q;
            }
        }
        else{
            printf("Location Not Found !! ");
        }
        
        
    }
}

void addAtbegin(){

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));


    printf("\nEnter Node Data :");
    scanf("%d", &temp->data);
    temp->next = NULL;
    
    if (root != NULL)
    {
        temp->next = root;
        root = temp;
    }
    else{
        root = temp;
    }
    
}

void deleteOddEle(){

    struct node *p;
    struct node *q;
  
    p = root;
    int i =0;

    while (p->next != NULL)
    {
        i++;
        
        p = p->next;

        if ( i % 2 == 0)
        {
            q = p->next; 
            p->next = q->next;
            q->next = NULL;
            free(q);
            
        }
        else{
            ("Even");

        }    
    }
}


void main()
{
    int ca;

    while (1)
    {
        printf("\nEnter | 1 - Add | 2 - Avg  | 3 - Add At Begin  | 4 - Display  | 5 - Add At Loc | 6 - Delete Odd Element |  0 - Exit | ");
        printf("\nEnter your choice - ");
        scanf("%d",&ca);
        switch (ca)
        {
        case 1:

            append();
            break;
        
        case 2:
            avg();
            break;

        case 3:
            addAtbegin();
            break;

        case 4:
            Display();
            break;

        case 5:
            addAtLoc();
            break;

        case 6:
            deleteOddEle();
            break;

        case 0:
            exit(1);
            break;

        default: printf("Invalid input");
            break;
        }
    }
}

