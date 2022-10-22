#include <stdio.h>
#include<stdlib.h>
int queue[5];
int front=0;
int rear =0;
void incert(void);
void delete(void);
void display(void);

void enqueue()
{
    if(5==rear)
    {
        printf("The quque is full\n");

    }
    else
    {
        int ele;
        printf("Enter data : ");
        scanf("%d",&ele);
        queue[rear]=ele;
        rear++;
    }
}
void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is Emty");

    }   
    else
    {
        int i=0;
        printf("deleted elemented %d \n",queue[front]);
        
        for(i=0;i<rear;i++)
        {
            queue[i]=queue[i+1];
        }
    }
}
void display()
{
    if(front==rear)
    {
        printf("Queu is empty");

    }
    else{
        int i;
        printf("Queue Element :");
        for(i=front;i<rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
void peek(){
    printf("Peek elemented %d \n",queue[front]);
}


void main()
{
    int ca;

    while (1)
    {
        printf("\nEnter | 1 - Incert | 2 - Delete | 3 - Display | 4 - Peek | 0 - Exit | Linear Queue");
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
            peek();
            break;

        case 0:
            exit(0);
            break;

        default: printf("Invalid Input\n");
            break;
        }
    }
}




