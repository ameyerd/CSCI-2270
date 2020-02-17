#include <iostream>

using namespace std;

struct Node {
  int key;
  Node* next;

};

class Queue { // DECLARE your class
  private:
    Node *head, *tail;
    bool isEmpty();
    bool isFull(); //linked lists can't fill up?!
    int queueSize; // not useful for our linked lists, but maybe wwant it for some reason
  public:
    Queue();
    void enqueue(int value);
    int dequeue(); // returns type of 'key'
    void printQueueSize(); // Wrapper to access private data
};

Queue::Queue() { // INITIALIZE your OBJECT's data
  // NULL vs nullptr ?
  // nullptr keep compiler to check thing better?
  head = nullptr;
  tail = nullptr;
  // don't need queueSize for this example, so I'll ignore it
}

void Queue::enqueue(int value) { // 20ms
  // linked lists can't be full, so we can continue
  // initalize our new node
  Node* newNode = new Node;
  newNode->key = value;
  newNode->next = nullptr;

  // connect it to the list
  if (head == nullptr) { // First in the list  // slightly > 4ms (runtime)
    head = newNode; //4ms
    tail = newNode; //4ms
  }
  else {
    tail->next = newNode; // 4ms
    tail = newNode; // 4ms
  }

}

int main() { // INITIALIZE your class OBJECT
  Queue myQ;

  return 0;
}
