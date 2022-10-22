#include <stdio.h>
#include<stdlib.h>
void enqueue(void);
void enqueue(void);
void display(void);
void peak(void);

 
struct node{
    int data;
    struct node* next;
};
struct node* front = 0;
struct node* rear = 0;






void enqueue(){
    struct node* newnode;
    newnode=(struct node*) malloc(sizeof(struct node));


    printf("enter Node  data to enqueue : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;


    if(rear==0)
    {
        front = rear = newnode;
        rear->next=front; 
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
    display();
}




void dequeue(){
    struct  node* temp;
    temp = front;

    if(front==NULL)  // underflow
    {
        printf("Queue is Empty");
    }

    else if(front==rear)// if single element
    { 
        front=rear=0;
        free(temp);
    }

    else
    {
        front=front->next;
        rear->next = front;
        free(temp);
    }
    display();
}





void peak(){
    if(front==NULL)  // underflow
    {
        printf("Queue is Empty");
    }
    else{
        printf("The peak / front is %d",front->data);
    }
}






void display(){
    struct node* temp;
    temp = front;
    if(temp==NULL)
    {
        printf("Link-list is empty");
    }
    else{
        while (temp->next!=front)//instead of temp != NULL because temp->will never become null as it is circular queue
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        //this loop will not printthe last node which points to the front address
        //therefore
        printf("%d-->",temp->data);
    }
    printf("\n\n");
}




void main()
{
    int ca;

    while (1)
    {
        printf("\nEnter | 1 - enqueue | 2 - dequeue  | 3 - Display | 4 - peak | 0 - Exit | Single link list - Incertion");
        printf("\nEnter your choice - ");
        scanf("%d",&ca);
        switch (ca)
        {
        case 1:
            enqueue();
            break;
        
        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            peak();
            break;

        case 0:
            exit(1);
            break;

        default: printf("Invalid input");
            break;
        }
    }
}
