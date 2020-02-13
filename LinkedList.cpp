#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
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
    
void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
}