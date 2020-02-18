#include "LinkedList.hpp"
#include <#iostream>

int main()
{
    LinkedList* ll = new LinkedList(); //some change
    ll->addFront(1);
    ll->addFront(2);
    ll->addEnd(3);
    ll->addAtIndex(1,7);
    //std::cout << ll->removeFront() << "\n";
    ll->display();
    int val = ll->getIndex(2);
    std::cout << val << "\n";
    delete ll;
}