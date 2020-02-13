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
int LinkedList::addEnd(int data, Node *head)
{
   Node *n2 = new Node;
   n2->data = data;
   n2->next = NULL;

   if(head == NULL)
   {
       head = n2;
   } else {
       Node *t = new Node;
       t = head;

       while(temp->next != NULL)
       {
           t = t->next;
       }
       t->next = last;
   }
   return head;
}

int LinkedList::getEnd()
{
    return this->head->data;
}

int LinkedList::removeEnd()
{
    Node* nTR = this->head;
    this->head = this->head->getNextNode();
    int val = nodeToReturn->getEnd();
    delete nTR;
    this->count--;
    return val;
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