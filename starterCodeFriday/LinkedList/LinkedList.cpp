#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    }

    else{

        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;

    }
}



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n){
  // implement a pointer that's equal to head
  Node *prev = head;
  Node *current = head;

 // implement an index counter
 int index = 0;
 int counter = 0;

 //move the current node all the way to n
 while(index != n+1)
 {
   current = current->next;
   index++;
   counter++;
 }

 // move both until current reaches the end
 while(current != NULL)
 {
   current = current->next;
   prev = prev->next;
   counter++;
 }


 if(counter == n)
 {
   //remove the head of list
   Node *temp = NULL;

   temp = head;
   head = head->next;

   delete temp;
   return;
 }

 cout << "counter: " << counter << endl;

 // create a temp value
 Node *temp = NULL;

 temp = prev->next;
 prev->next = prev->next->next;

 delete temp;


}
