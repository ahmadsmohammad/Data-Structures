#ifndef T_LINKED_LIST
#define T_LINKED_LIST
#include<iostream>

template <typename T>

class TSLList {
    public:

        // Constructor
        TSLList() {
            head = nullptr;
        }

        //D Destructor
        ~TSLList() {
            clearList();
        }

        // prints the info content and address of each node in the list
        void printAll() const {
            for (TSLLNode *tmp = head; tmp != nullptr; tmp = tmp->next)
                std::cout << "->[" << tmp->info << "," << tmp << "]";
            std::cout << std::endl;
        }

        // Inserts node in order (see assignment specification for details)
        void insertInOrder(T number)
        {
            TSLLNode *newnode, *cur, *prev;

            // dynamically allocating memory to new node and giving value passed in param. 
            newnode = new TSLLNode(number);
            newnode -> info = number;

            // preparing cur and prev for traversal
            cur = head;
            prev = NULL;

            // checks if head is NULL and if so sets the newnode to be head (empty list)
            if(!head)
                {
                    head = newnode;
                    newnode->next = NULL;
                }
            // otherwise traverse until we find valie
            else
                {
                    // traversal loop which makes sure cur != NULL and stops when we reach
                    // where we want to insert node.
                    while(cur != NULL && cur->info <= number)
                    {
                        prev = cur;
                        cur = cur->next;
                    }
                    // sets head to equal new node if both cur and prev are NULL
                    // ie. while loop did not run
                    if(prev == NULL)
                    {
                        head = newnode;
                        newnode->next = cur;
                    }
                    // otherwise set prev->next to newnode and newnode->next to cur
                    // in order to keep cur 2 nodes ahead of prev and not get seg fault
                    else
                    {
                        prev->next = newnode;
                        newnode->next = cur;
                    }
                }

}

        // Deletes an occurrence of argument (see assignment specification for details)
        T deleteVal(T number)
        {
            TSLLNode *cur, *prev;

            cur = head;
            // checks if head = NULL and if so exits
            if(!head)
                return -1;

            // checks if head is node to be deleted if so deletes and returns cur which = head
            if(head->info == number)
            {
                cur = head;
                head = head->next;
                int x = cur-> info;
                delete cur;
                cur = head;
                return x;

            }
            //other wise node to be deleted is in list somewhere...
            else
            {

                // traversal loop to locate node to be deleted
                while(cur != NULL && cur->info != number)
                {
                    prev = cur;
                    cur = cur->next;
                }
                // makes sure cur data = number because if not we would get seg fault 
                // trying to delete NULL node 
                if(cur -> info == number)
                {
                    // makes sure all data from cur is wiped before delete and returns value we
                    // were looking for
                    prev-> next = cur->next;
                    cur-> next = NULL;
                    prev = cur;
                    int y = prev->info;
                    delete cur;
                    return y;
                }

            }

            }

        // Deletes all occurrences of argument (see assignment specification for details)
        void deleteAllVal(T number)
        {
            TSLLNode *cur, *prev;

            // checks if head = null.. if so exits
            if(!head)
                return;
            // if head = number we want to delete we delete head and set head to cur 
            // while head is = number we want gone
            if(head->info == number)
            {
                while(head->info == number)
                {
                    cur = head->next;
                    delete head;
                    head = cur;
                }
            }
            // otherwise the number we want to delete is in the list somewhere...
            else
            {
                // set cur =  head for traversal
                cur = head;

                // while list is a list and cur's data != number, traverse the list
                while(cur != NULL && cur->info != number)
                {
                    prev = cur;
                    cur = cur->next;
                }
                // if cur -> info = number then enter while loop and delete nodes 
                // until it is not equal to number 
                if(cur != NULL && cur -> info == number)
                {
                    while(cur->info == number)
                    {
                        prev->next = cur->next;
                        delete cur;
                        prev = cur;
                        cur = cur->next;
                    }
                }
            }
        }

        // Clears the list (deallocates memory - see assignment specification for details)
        void clearList()
        {
            TSLLNode *cur;
            while(head)
                {
                    // clearing message
                    std::cout << "Clearing " << head->info <<' '<<&head->info<< std::endl;
                    //setting cur to head to delete bc we cant delete head
                    cur = head;
                    // setting head to next node in list
                    head = head -> next;
                    // deleting old head
                    delete cur;
        }
        }

    private:
        // Node stored in linked list
        struct TSLLNode { 
            TSLLNode(T el = T()) {
                info = el;
                next = nullptr; }
                T info;
                TSLLNode *next; };


        TSLLNode *head;   // head of the list
};


#endif

