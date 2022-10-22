#include <stdio.h>  
#define SIZE 20  
 int array[SIZE];  // declaration of array type variable.  
int top1 = -1;  
int top2 = SIZE;  
   
//Function to push data into stack1  
void push1 (int data)  
{  
// checking the overflow condition  
  if (top1 < top2 - 1)  
  {  
      top1++;  
    array[top1] = data;  
  }  
  else  
  {  
    printf ("Stack is full");  
  }  
}  
// Function to push data into stack2  
void push2 (int data)  
{  
// checking overflow condition    
if (top1 < top2 - 1)  
  {  
    top2--;  
    array[top2] = data;   
  }  
  else  
  {  
    printf ("Stack is full..\n");  
  }  
}  
   
//Function to pop data from the Stack1  
void pop1 ()  
{  
// Checking the underflow condition   
 if (top1 >= 0)  
  {  
    int popped_element =0;
    popped_element = array[top1];  
    top1--;  
     
    printf ("%d is being popped from Stack 1\n", popped_element);  
  }  
  else  
  {  
    printf ("Stack is Empty \n");  
  }  
}  
// Function to remove the element from the Stack2  
void pop2 ()  
{  
// Checking underflow condition    
if (top2 < SIZE)  
  {  
      int popped_element = 0;
      popped_element = array[top2];  
    top2--;  
     
    printf ("%d is being popped from Stack 1\n", popped_element);  
  }  
  else  
  {  
    printf ("Stack is Empty!\n");  
  }  
}  
   
//Functions to Print the values of Stack1  
void display_stack1 ()  
{  
  int i;  
  for (i = top1; i >= 0; --i)  
  {  
    printf ("%d \n", array[i]);  
  }  
 
}  
// Function to print the values of Stack2  
void display_stack2 ()  
{  
  int i;  
  for (i = top2; i < SIZE; ++i)  
  {  
    printf ("%d \n", array[i]);  
  }  

}  
   
int main()  
{  
  int ar[SIZE];  
  int i;  
  int num_of_ele;  
   
  printf ("We can push a total of 20 values\n");  
  printf ("Enter 0 to switch between stack\n");  
   
  //Number of elements pushed in stack 1 is 10  
  //Number of elements pushed in stack 2 is 10  
   
// loop to insert the elements into Stack1

for (i = 1; i <= 20; ++i)  
  {  
    int num;
    if(num==0)
    {
        break;
        
    }
    else
    {
        push1(num);  
        printf ("Enter the Value Pushed in Stack 1 : \n");  
        scanf("%d",&num);
    }
    
  }  
// loop to insert the elements into Stack2.    
for (i = 1; i <= 20; ++i)  
  {  
    int num;
    if(num==0)
    {
        break;
        
    }
    else
    {
        push2(num);  
        printf ("Enter the Value Pushed in Stack 2 : \n");  
        scanf("%d",&num);
    }
    
  }  
   
  //Print Both Stacks  
  display_stack1 ();  
  display_stack2 ();  
   
 
  for (i = 1; i <= 20; ++i)  
  {  
    int input;
    if(input==0)
    {
        break;
        
    }
    else
    {
        pop1 ();  
        printf ("Enter 1 to pop the element from top oof stack 1 else enter 0 \n");  
        scanf("%d",&input);
    }
    
  }  

  //p0p from stack 2
  for (i = 1; i <= 20; ++i)  
  {  
    int input;
    if(input==0)
    {
        break;
        
    }
    else
    {
        pop2 ();  
        printf ("Enter 1 to pop the element from top oof stack 2 else enter 0 \n");  
        scanf("%d",&input);
    }
    
  }  
  display_stack1 ();  
  display_stack2 ();

  return 0;  
}  