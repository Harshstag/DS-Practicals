#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct employ
{
    int id;
    char name[20];
    long salary;
    struct employ* next;

};
struct employ* root = NULL;



void add(){
    struct employ* temp ;
    temp = (struct employ*)malloc(sizeof(struct employ));

    printf("\nEnter Emp data ");

    printf("\nEnter Emp ID' : ");
    scanf("%d",&temp->id);

    printf("Enter Emp Name' : ");
    scanf("%s",&temp->name);

    printf("Enter Emp salary' : ");
    scanf("%d",&temp->salary);
    temp->next = NULL;

    if (root ==  NULL)
    {
        root = temp;

    }
    else{
        struct employ *p;
        p = root;

        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
void delete(){
    struct employ *temp;
    temp = root;
    int delId;

    printf("Enter Emp ID' to delete :  ");
    scanf("%d", &delId);

    while (temp ->next != NULL)
    {
        if (delId == temp->id)
        {
            struct employ* p;

            p = temp->next;
            temp->next = p;
            
            free(temp);
        
        }
        

        temp = temp->next;// ++
    }
    
}
void search(){
    struct employ* temp;
    temp = root;
    int searchId;
    printf("Enter the Emp Id' to Search the Emp details : ");
    scanf("%d",&searchId);
    while (temp != NULL)
    {
        if (searchId == temp->id)
        {
            printf("Emp Found  \nEmp Name : %s \nEmp salary : %d \n", temp->name, temp->salary);
        }
        else{
            printf("Emp Not Found !!!");
        }
        
        temp = temp->next; //++
    }
    
}
void main()
{
    int ca;

    while (1)
    {
        printf("\nEnter | 1 - Add | 2 - Delete  | 3 - Search | 4 - update | 0 - Exit | ");
        printf("\nEnter your choice - ");
        scanf("%d",&ca);
        switch (ca)
        {
        case 1:
            add();
            break;
        
        case 2:
            delete();
            break;

        case 3:
            search();
            break;

        case 4:
            // update();
            break;

        case 0:
            exit(1);
            break;

        default: printf("Invalid input");
            break;
        }
    }
}
