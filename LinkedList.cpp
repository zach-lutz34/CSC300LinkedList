#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
}

struct Node { 
   int data; 
   struct Node *prev; 
   struct Node *next; 
}; 
struct Node* head = NULL; 
void insert(int newdata) { 
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
   newnode->data  = newdata; 
   newnode->prev = NULL; 
   newnode->next = head;     
   if(head !=  NULL) 
      head->prev = newnode ;     
   head = newnode; 
}   

void LinkedList::addFront(int payload)
{
    Node* n = new Node(payload);

    if(!this->head)
    {
        this->head = n;
    }
    else
    {
        n->setNextNode(this->head);
        this->head = n;
    }
    this->count++;
}

int LinkedList::getFront()
{
    return this->head->getPayload();
}

int LinkedList::removeFront()
{
    Node* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    int val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    return val;
}

// hw 2.13
void LinkedList::addEnd(int payload)
{
   if(!this->head)
   {
       this->addFront(payload);
   } 
   else 
   {
       Node* n = new Node(payload);
       Node* currNode = this->head;
       while(!currNode->getNextNode())
       {
           currNode = currNode->getNextNode();
       }
       currNode->setNextNode(n);
       this->count++;
   }
}

int LinkedList::getEnd()
{
    Node* currNode = this->head;
    while(currNode->getNextNode())
    {
        currNode = currNode->getNextNode();
    }
    return currNode->getPayload();
}

int LinkedList::removeEnd()
{
    if(!this->head->getNextNode())
    {
        return this->removeFront();
    }
    else
    {
        Node* last = this->getEnd();
        Node* next = this->head;
        while(!next->getNextNode() != last)
        {
            next = next->getNextNode();
        }
        next->setNextNode(0);
        int val = last->getPayload();
        delete last;
        this->count--;
        return val;
    }
}

void LinkedList::addAtIndex(int index, int payload)
{
    if(index == 0)
    {
        this->addFront(payload);
    }
    else if (index == this->count)
    {
        this->addEnd(payload);
    }
    else
    {
        Node* newNode = new Node(payload);
        Node* firstPoint = this->head->getNextNode();
        Node* beforePoint = this->head;

        for(int i = 1; i<index; i++)
        {
            firstPoint = firstPoint->getNextNode();
            beforePoint = beforePoint->getNextNode();
        }

        beforePoint->setNextNode(newNode);
        newNode->setNextNode(firstPoint);
        this->count++; 
    } 
}

int LinkedList::removeIndex(int index)
{
    int val;
    if(index == 0)
    {
        val = this->removeFront();
    }
    else if (index == this->count-1)
    {
        val = this->removeEnd();
    }
    else
    {
        Node* firstPoint = this->head->getNextNode();
        Node* beforePoint = this->head;

        for(int i = index-1; i>0; i--)
        {
            firstPoint = firstPoint->getNextNode();
            beforePoint = beforePoint->getNextNode();
        }
        val = firstPoint->getPayload();
        beforePoint->setNextNode((firstPoint->getNextNode()));
        firstPoint->setNextNode(0);
        this->count--;
    } 
    return val;
}

int LinkedList::getIndex(int index)
{
    Node* traverse = this->head;
    for(int i = index; i>0; i--)
    {
        traverse = traverse->getNextNode();
    }
    return traverse->getPayload();
}

int LinkedList::sort()
{
    int array[] = {3, 2, 1, 7};
    int n = sizeof(array)/sizeof(array[0]);

    std::sort(array, array + n);

    for (int con &i: array)
    {
        std::cout << i << ' ';
    }
    return 0;
}
    
void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
}