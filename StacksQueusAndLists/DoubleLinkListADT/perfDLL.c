/* 
 * File:   perfDLL.c
 * Author: Ajinkya Wavare
 *
 * Created on February 2, 2015, 10:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "DoubleList-interface.h"
#include "List-Interface.h"
/*There are two integer variables defined in other modules*/
/*The extern keyword is for the c compiler to believe that these variables are declared in other modules*/

extern int DL_Ptr_Travs_Count;
extern int L_Ptr_Travs;


int check_value(char);//To check if the char corresponds to a digit
char num_read(node *,dnode *);// to read the number into an initial list

//Print list and double lists
void print_list(node *);//To print the list
void Dprint_list(dnode *);

//Add linked list and double linked lists.
node * add(node *,node *);
dnode * Dadd(dnode *,dnode *);

int main(int argc, char** argv) {
    
    //Declaration of 3 double linked lists.
    dnode * dnum1;
    dnode * dnum2;
    dnode * dresult;
    node * num1;
    node * num2;
    node * result;
    char read_val;
    
    // Read the number1
    scanf("%c",&read_val);
    if((check_value(read_val)) && (read_val!= '\n'))
    {
        //initial node of num1.
        num1 = (node *)malloc(sizeof(node));
        num1->value = read_val-48;
        num1->next = NULL;
        
        dnum1 = (dnode *)malloc(sizeof(dnode));
        dnum1->value = read_val-48;
        dnum1->next = NULL;
        dnum1->prev = NULL;

    }
    read_val = num_read(num1,dnum1);
    //If number reading returned a meaningless character,exit.
    if(!check_value(read_val)) return -1;
    
    //Read the number2
    scanf("%c",&read_val);
    if((check_value(read_val)) && (read_val!= '\n'))
    {
        //initial node of num2.
        num2 = (node *)malloc(sizeof(node));
        num2->value = read_val-48;
        num2->next = NULL;
        
        dnum1 = (dnode *)malloc(sizeof(dnode));
        dnum1->value = read_val-48;
        dnum1->next = NULL;
        dnum1->prev = NULL;
        
    }
    read_val = num_read(num2,dnum2);
    //If number reading returned a meaningless character,exit.
    if(!check_value(read_val)) return -1;
    result = add(num1,num2);
    dresult = Dadd(dnum1,dnum2);
    
    //Print list
    print_list(num1);
    print_list(num2);
    printf("%d is the number of pointer traversals with Linked List\n" ,L_Ptr_Travs );
    print_list(result);

    //Print Double list
    Dprint_list(dnum1);
    Dprint_list(dnum2);
    printf("%d is the number of pointer traversals with Double Linked List\n" ,DL_Ptr_Travs_Count );
    Dprint_list(dresult);

    
    return (EXIT_SUCCESS);
}


int check_value(char read_val)
{
    //Checks if the value those are read are meaningful or not.
    if (read_val == ' ') return -1;
    if (read_val <48 || read_val > 57) return -1;
    return 1;
}
char num_read(node * num,dnode * num2)
{
    char read_val;
    node * newnode;
    dnode * dnum1;
    dnode * temp;
    scanf("%c",&read_val);
    while (check_value(read_val) && read_val != '\n' )
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->value = read_val - 48;
        last(num)->next = newnode;
        
        dnum1 = (dnode *)malloc(sizeof(dnode));
        dnum1->value = read_val-48;
        dnum1->next = NULL;
        dnum1->prev = Dlast(num2);
        Dlast(num2)->next = dnum1;
        

        scanf("%c",&read_val);
    }
    return read_val;
}
void print_list(node * num)
{
    while(num->next != NULL)
    {
        printf("%d",num->value);
        num = num->next;
    }
    printf("\n");
    return ;
    
}
// Function to add two numbers.
node * add(node * num1,node * num2)
{
    node * result;
    node * newnode;
    node * l1;
    node * l2;
    int carry = 0,sum = 0;
    // sum/10 = carry
    
    l1 = last(num1);
    l2 = last(num2);
    newnode = (node *)malloc(sizeof(node));
    sum = carry + l1->value + l2->value;
    newnode->value = (sum)%10;
    carry = sum/10;
    result = newnode;
    while((before(num1,l1)!= NULL) ||(before(num2,l2)!= NULL))
    {
        l1 = before(num1,l1);
        l2 = before(num2,l2);
        newnode = (node *)malloc(sizeof(node));
        sum = carry + l1->value + l2->value;
        newnode->value = (sum)%10;
        carry = sum/10;
        // equivalent to , insertBefore(result,first(result),newnode->value)
        newnode->next = result; //newnode is made the starting of the list.
        result = newnode;
    }
    if (before(num1,l1)== NULL)
    {
        while(before(num2,l2) != NULL)
        {
            l2= before(num2,l2);
            newnode = (node *)malloc(sizeof(node));
            sum = carry + l2->value;
            newnode->value = (sum)%10;
            carry = sum/10;
            // equivalent to , insertBefore(result,first(result),newnode->value)
            newnode->next = result; //newnode is made the starting of the list.
            result = newnode;
        }
    }
    if (before(num2,l2)== NULL)
    {
        while(before(num1,l1) != NULL)
        {
            l1= before(num1,l1);
            newnode = (node *)malloc(sizeof(node));
            sum = carry + l1->value;
            newnode->value = (sum)%10;
            carry = sum/10;
            // equivalent to , insertBefore(result,first(result),newnode->value)
            newnode->next = result; //newnode is made the starting of the list.
            result = newnode;
        }
    }
    if (carry != 0)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->value = carry;
        newnode->next = result;
        result = newnode;
    }
    return result;
}

void Dprint_list(dnode * num)
{
    while(num->next != NULL)
    {
        printf("%d",num->value);
        num = num->next;
    }
    printf("\n");
    return ;

}
    
dnode * Dadd(dnode * num1,dnode * num2)
{
    dnode * result;
    dnode * newnode;
    dnode * l1;
    dnode * l2;
    int carry = 0,sum = 0;
    // sum/10 = carry
    
    l1 = Dlast(num1);
    l2 = Dlast(num2);
    newnode = (dnode *)malloc(sizeof(dnode));
    sum = carry + l1->value + l2->value;
    newnode->value = (sum)%10;
    carry = sum/10;
    newnode->next = NULL;
    newnode->prev = NULL;
    result = newnode;
    while((Dbefore(num1,l1)!= NULL) ||(Dbefore(num2,l2)!= NULL))
    {
        l1 = Dbefore(num1,l1);
        l2 = Dbefore(num2,l2);
        newnode = (dnode *)malloc(sizeof(dnode));
        sum = carry + l1->value + l2->value;
        newnode->value = (sum)%10;
        carry = sum/10;
        // equivalent to , insertBefore(result,first(result),newnode->value)
        newnode->next = result; //newnode is made the starting of the list.
        result->prev = newnode;
        result = newnode;
    }
    if (Dbefore(num1,l1)== NULL)
    {
        while(Dbefore(num2,l2) != NULL)
        {
            l2= Dbefore(num2,l2);
            newnode = (dnode *)malloc(sizeof(dnode));
            sum = carry + l2->value;
            newnode->value = (sum)%10;
            carry = sum/10;
            // equivalent to , insertBefore(result,first(result),newnode->value)
            newnode->next = result; //newnode is made the starting of the list.
            result->prev = newnode;
            result = newnode;
        }
    }
    if (Dbefore(num2,l2)== NULL)
    {
        while(Dbefore(num1,l1) != NULL)
        {
            l1= Dbefore(num1,l1);
            newnode = (dnode *)malloc(sizeof(dnode));
            sum = carry + l1->value;
            newnode->value = (sum)%10;
            carry = sum/10;
            // equivalent to , insertBefore(result,first(result),newnode->value)
            newnode->next = result; //newnode is made the starting of the list.
            result->prev = newnode;
            result = newnode;
        }
    }
    if (carry != 0)
    {
        newnode = (dnode *)malloc(sizeof(dnode));
        newnode->value = carry;
        newnode->next = result;
        result->prev = newnode;
        result = newnode;
    }
    return result;
}
