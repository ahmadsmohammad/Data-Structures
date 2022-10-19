#include "intsllist.h"
#include<iostream>

using namespace std;



void IntSLList::insertInOrder(int number)
{   
    IntSLLNode *newnode, *cur, *prev;
    newnode = new IntSLLNode(number);
    cur = head;
    prev = NULL;
    
    if(!head)
        {   
            head = newnode; 
            newnode->next = NULL;
        }
    else
        {   
            cur = head;
            prev = NULL;
            
            while(cur != NULL && cur->info <= number)
            {   
                prev = cur;
                cur = cur->next;
            }
            
            if(prev == NULL)
            {   
                head = newnode; 
                newnode->next = cur;
            }
            
            else
            {   
                prev->next = newnode;
                newnode->next = cur;
            }
        }

}

int IntSLList::deleteVal(int number)
{   
    IntSLLNode *cur, *prev;
    if(!head)
        return 0; 
    if(head->info == number)
    {   
        cur = head->next;
        delete head;
        head = cur;
    }
    else
                                               
    {
        cur = head;

        while(cur != NULL && cur->info != number)
        {
            prev = cur;
            cur = cur->next;
        }

        if(cur)
        {
            prev->next = cur->next;
            delete cur;
        }
    }
}

void IntSLList::deleteAllVal(int number)
{
    IntSLLNode *cur, *prev;
    if(!head)
        return;
    if(head->info == number)
    {
        while(head->info == number)
        {
            cur = head->next;
            delete head;
            head = cur;
            head = head->next;
        }
    }
    else
    {
        cur = head;

        while(cur != NULL && cur->info != number)
        {
            prev = cur;
            cur = cur->next;
        }

        if(cur)
        {
            while(cur->info == number)
            {
                prev->next = cur->next;// does this make sense????
                delete cur;
                prev = cur;
                cur = cur->next;
            }
        }
    }
}


void IntSLList::clearList()
{
    IntSLLNode *cur, *prev;
    while(cur)
        {
            cout << "Clearing" << endl;
            prev->next = cur->next;
            delete cur;
            prev = cur;
            cur = cur->next;

        }

}

                          