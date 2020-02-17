#include <iostream>
using namespace std;

// struct Node {
//   int key;
//   Node *next;
// };
//
// int main(int argc, char const *argv[]) {
//
//   Node *pres = head;
//
//   int count = 0;
//   while(pres!= NULL && count <3) {
//     if(pres->key == 5) {
//       count = count +1;
//     }
//     pres = pres->next;
//   }
//   cout << pres->key << endl;
// }

struct node {
  int data;
  node *next;
};

class list
{
  private:
    node *head, *tail;
  public:
    list() {
      head = NULL;
      tail = NULL;
    }
};


// delete the node after node P

void createnode(int value) {
  node *temp = new node;
  temp->data = value;ˇ
  temp->next = NULL;

  if(head == NULL) {
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else {
    tail->next = temp;
    tail = temp;
  }
}

void display() {
  node *temp = new node;
  temp = head;
  while(temp!= NULL) {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}
