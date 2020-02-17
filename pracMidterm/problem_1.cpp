#include <iostream>

using namespace std;

struct Node{
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

bool lengthIsEven(Node *head) {

  Node *current = head;

  if(current == NULL) return true;

  int counter = 0;
  while(current != NULL)
  {
    counter++;
    current = current->next;
  }

  if(counter % 2 == 0)
  {
    return true;
  }

  return false;


}

int main() {

  Node *head = NULL;

  // push(&head, 3);
  // push(&head, 9);
  // push(&head, 2);
  // push(&head, 4);
  // push(&head, 1);
  // push(&head, 2);

  cout << "length even? : " << lengthIsEven(head) << endl;

  return 0;

}

//ARRAYS
//  methods(insert/delete/search)
      // shifting operations
        // holes in array
        // search is NOT a constant time operation
// array doubling
      // parameter passing
        // make sure you delete the old data

//getline .. stringstream
// input
// lINKED LIST
    // singly
    // Methods: think pseudocode !!
    // ampersand &
