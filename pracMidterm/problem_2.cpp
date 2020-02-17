#include <iostream>

using namespace std;

struct Node {
  int key;
  Node *next;

};

void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->key = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

Node *deleteNegatives(Node *head)
{
  Node *current = head;

  if(current == NULL) return NULL;

  while(current != nullptr)
  {
    if(current->key < 0) {
      //delete node
      Node *temp = NULL;

      temp = current->next;

      delete current;
      current = temp;

    }

    current = current->next;
  }

  return head;


}

int main() {

  Node *head = NULL;

  push(&head, -3);
  push(&head, 9);
  push(&head, 2);
  push(&head, -4);
  // push(&head, 1);
  // push(&head, 2);

  cout << "new head : " << deleteNegatives(head) << endl;

  return 0;

}
