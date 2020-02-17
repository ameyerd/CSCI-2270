#include <iostream>
#include <string>
#include "ProducerConsumer.hpp"
using namespace std;

ProducerConsumer::ProducerConsumer()
{
  queueFront = 0;
  queueEnd = 0;
}

bool ProducerConsumer::isEmpty()
{
  if (counter == 0)
  {
    return true;
  }

  return false;
}

bool ProducerConsumer::isFull()
{
  if(counter == SIZE)
  {
    return true;
  }

  return false;
}

void ProducerConsumer::enqueue(string item)
{

  if(isFull())
  {
    cout << "Queue full, cannot add new item" << endl;
  }
  else
  {
    //add item to the end of the queue
    queue[queueEnd] = item;
    counter++;

    if(queueEnd == SIZE - 1)
    {
      //here
      queueEnd = 0;
    }
    else
    {
      queueEnd++;
    }

  }

}

void ProducerConsumer::dequeue()
{
  if(isEmpty())
  {
    cout << "Queue empty, cannot dequeue an item" << endl;
  }
  else
  {
    queue[queueEnd] = queue[queueFront];
    counter--;

    if(queueFront == SIZE - 1)
    {
      queueFront = 0;
    }
    else
    {
      queueFront++;
    }
  }
}

int ProducerConsumer::queueSize()
{
  return counter;
}

string ProducerConsumer::peek()
{
  if(isEmpty())
  {
    cout << "Queue empty, cannot peek" << endl;
    return "";
  }
  else
  {
    return queue[queueFront];
  }
}
