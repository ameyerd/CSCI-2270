#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    Node *nn = new Node;
    nn->key = key;
    nn->next = nullptr;

    // TODO Complete this function, handle the case when you're enqueuing in an empty queue

    if (isEmpty()){
      // set both front and end to be nn
      queueFront = nn;
      queueEnd = nn;
    }
    else {
        //modify End
        // step one: end -> next
        // step two: reset end

        queueEnd->next = nn;
        queueEnd = nn;

    }
}

//TODO
void QueueLL::dequeue()
{
    if(!isEmpty())
    {
        // TODO Complete this function, handle the case when your queue becomes empty after dequeuing
        // node temp to save the original queue queueFront
        // reset the queue fornt
        // delete the orginlal queue front by temp
        Node *temp = new Node;
        temp = queueFront;

        queueFront = queueFront->next;

        delete temp;

    }
    else{
        cout<<"queue is empty. can not deque"<<endl;
    }
}

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}
