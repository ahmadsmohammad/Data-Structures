#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
#include<iostream>

class IntSLList {
    public:

        // Constructor
        IntSLList() {
            head = nullptr;
        }

        //D Destructor
        ~IntSLList() {
            clearList();
        }

        // prints the info content and address of each node in the list
        void printAll() const {
            for (IntSLLNode *tmp = head; tmp != nullptr; tmp = tmp->next)
                std::cout << "->[" << tmp->info << "," << tmp << "]";
            std::cout << std::endl;
        }

        // Inserts node in order (see assignment specification for details)
        void insertInOrder(int);

        // Deletes an occurrence of argument (see assignment specification for details)
        int deleteVal(int);

        // Deletes all occurrences of argument (see assignment specification for details)
        void deleteAllVal(int el);

        // Clears the list (deallocates memory - see assignment specification for details)
        void clearList();

    private:
        // Node stored in linked list
        struct IntSLLNode {
            IntSLLNode(int el = 0) {
                info = el;
                next = nullptr;
            }
            int info;
            IntSLLNode *next;
        };

        IntSLLNode *head;   // head of the list
};

#endif

