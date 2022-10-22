//Assignment II-C-> Equivalence Class 
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *link;
};
struct node *seq[100];
bool out[100];


// PHASE : 1.1 Insert 
// This code inserts the element in the form of stack, 
// as per the criteria of quivalence relation : 
// 1.reflexsive, 2.Symetric, 3.Transitive

struct node *insert(struct node **seq, int data)
{
    struct node *newnode = ((struct node *)malloc(sizeof(struct node)));
    newnode->data = data;
    newnode->link = NULL; // Doing it by default, will update it later in code

    if(*seq == NULL) // when its the first relation with x or y
    {
        *seq = newnode; // simpely updating top of list   
    }
    else
    {
        // this operation performs as a stack, updating the top last in is on top
        newnode->link = *seq; // right side connection first, so we dont lose the list
        *seq = newnode; // updated the top
    }
    return *seq; // returning root / top of the list
}


//PHASE : 1.2 Display
// Displaying the equivalence Relation 

void DisplayRelation(struct node **seq, int num)
{
    for (int i = 1; i <= num; i++)
    {
        struct node *temp = seq[i];
        printf("seq[%d] : ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("NULL \n");
    }
}


// PHASE : 2 
// 
struct node *EquivalenceClass(struct node **seq, int num)
{
    struct node *p = NULL;
    int done;
    int data;

    for (int i = 1; i <= num;i++)
    {
        if (out[i]== true)
        {
            printf("\nClass : \t%d",i);
            out[i] = false;
            struct node *temp = seq[i];
            struct node *top = NULL;
            done = 0;
            do
            {
                while (temp != NULL)
                {
                    data = temp->data;
                    if (out[data]==true)
                    {
                        printf("\t%d", data);// or temp->data
                        out[data] = false;

                        struct node *p = temp->link; // we are doing this so that we so that we dont mill this conncetion to rest of the list
                        temp->link = top; // as we are updatind it top
                        top = temp;
                        temp = p;
                    }
                    else
                    {
                        temp = temp->link;
                    }
                }

                if(top == NULL)
                {
                    done = 1;
                }
                else
                {
                    temp = seq[top->data];
                    top = top->link;
                }
            } while (done != 1);
        }
    }
}


int main()
{
    int n, x, y;
    printf("Enter number of Objects you want to Enter : ");
    scanf("%d", &n);

    for (int i = 0; i <= n;i++)
    {
        seq[i] = NULL;
    }


    for (int i = 0; i <= n;i++)
    {
        out[i] = true;
    }
    int ch = 1;
 
    while (ch !=0)
    {
        printf("Enter the relation ( x # y ) : \n");
        scanf("%d", &x);
        scanf("%d", &y);

        seq[x] = insert(&seq[x], y);
        seq[y] = insert(&seq[y], x);

        printf("0 to exit :");
        scanf("%d", &ch);
        printf("\n");
    }
    DisplayRelation(&seq[0], n);// Phase 1 of the code displaying the equivalence relation
    EquivalenceClass(&seq[0], n);

}