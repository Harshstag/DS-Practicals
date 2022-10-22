//Assignment II-B-> Multiplication of two polynomials using Linked List 
#include<stdio.h>
#include<stdlib.h>
struct node {
    float coeff;
    int expo;
    struct node* link;
};
struct node* head1 = NULL;
struct node* head2 = NULL;


// This piece of code is writen to sort the link list in decending order
// As the  addition of the polynomials are much easier in decending order 
// this will reduce the time complexcity of the  code .

struct node* insert(struct node* head, float  co, int ex)
{
    struct node *p; // for traversing
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->coeff = co;
    temp->expo = ex;
    temp->link = NULL;

    // If it is the first node in the list or 
    //the expo of present node is greter than the head expo / first term expo
    
    if (head==NULL || ex >head->expo)
    {
        temp->link = head; // right side connection first
        head = temp;   
    }

    else
    {
        p = head; // to traverse 

        //this wile loop will run till end 
        while(p->link!= NULL && p->link->expo >= ex)
        {
            p = p->link;
        }
        temp->link = p->link;
        p->link = temp;
    }
    return head;
}



// In this piece of code, we are onlu taking the input of coeff and expo with number of term 
// And we are calling insert method to sort the link list in decending order
// So every time you enter one term ex. 2x^2 this code will call insert method 
// And  Store this firt term in decending order 

struct node* creat(struct node* head)
{
    int n;
    float coeff;
    int expo;
    int i;

    printf("\nEnter the number of terms you want : ");
    scanf("%d", &n);
    for (i=0; i<n;i++)
    {
        printf("\nEnter the coeff of %d term : ", i+1);
        scanf("%f", &coeff);

        printf("Enter the Expo of %d term : ", i+1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo); // to sort the Equation in decending order
    }
    return head;
}


void display(struct node* head)
{
    if (head == NULL)
    {
        printf("EMPTY ! ! ! No polynomial found");
    }
    else
    {
        struct node *temp = head;
        while (temp!=NULL)
        {
            printf(" ( %.1fx^%d ) ", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp!=NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
            
        }
        
    }
}




void polyMult()
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *ResultHead = NULL; // result

    if(head1==NULL  || head2==NULL)
    {
        printf("\nEmpty ! ! ! ");
    }
    
    
    while (ptr1!=NULL)
    {
        while (ptr2!=NULL)
        {
            ResultHead = insert(ResultHead, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }
    printf("\nResult     : ");
    display(ResultHead);
}

int main()
{
    printf("\nEnter the Polynomial 1st  Equation : ");
    head1 = creat(head1);//creating the 1st polynomial equation

    printf("\nEnter the Polynomial 2nd  Equation : ");
    head2 = creat(head2);//creating the 2nd polynomial equation

    printf("\nEquation 1 : ");
    display(head1);
    printf("\nEquation 2 : ");
    display(head2);

    polyMult(head1, head2);
    printf("\n");
}
