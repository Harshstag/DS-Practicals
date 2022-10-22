#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* left;
    int data;
    struct node* right;
};
struct node* create()
{
    struct node* newnode=((struct node*)malloc(sizeof(struct node)));
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void insert(struct node** root, int data)
{
    struct node* temp=*root;
    if(temp==NULL)
    {
        struct node* newnode=create();
        newnode->data= data;
        *root= newnode;
        return;
    }
    if((temp->data)>data)
    {
        insert(&(temp->left),data);
    }
    else
    {
        insert(&(temp->right),data);
    }
}
int minElement(struct node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
struct node* delete(struct node* root, int num)
{
    struct node* temp=root;
    if(temp==NULL)
    {
        printf("number not found");
        return root;
    }
    else if((temp->data)>num)
    {
        root->left=delete(temp->left,num);
    }
    else if((temp->data)<num)
    {
        root->right=delete(temp->right,num);
    }
    else
    {
        if(root->left==NULL&& root->right==NULL)
        {
            free(temp);
            return NULL;
        }
        else if(root->left==NULL)
        {
            int min=minElement(temp->right);
            root->data=min;
            delete((root->right),min);
        }
        else
        {
            int max= (temp->right)->data;
            root->data=max;
            delete((root->left),num);
        }
    }
    return root;
}
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}
int main()
{
    struct node* root=create();
    root=NULL;
    int choice=0;
    do
    {
        printf("\n1. create\t2. delete\t3. inorder\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int data;
                printf("please enter the number\n");
                scanf("%d",&data);
                insert(&root,data);
                break;
            }
            case 2:
            {
                int num;
                printf("please enter the number to delete\n");
                scanf("%d",&num);
                delete(root,num);
                break;
            }
            case 3:
            {
                inorder(root);
                break;
            }
        }
    }while(choice!=0);
}