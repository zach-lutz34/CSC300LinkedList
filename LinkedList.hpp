#ifdef LinkedList_hpp
#define LinkedList_hpp
#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        int count;

    public:
        LinkedList();
        void addFront(int payload);
        int getFront();
        int removeFront();
        //hw 3 methods below
        void addEnd(int payload);
        int getEnd();
        int removeEnd();
        //hw for 2.18 (3 methods below)
        void addAtIndex(int index, int payload);
        int getIndex(int index);
        int removeIndex(int index);
        void display();
};
#endif /* LinkedList_hpp */