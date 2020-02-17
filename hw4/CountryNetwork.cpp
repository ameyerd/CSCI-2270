/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
  head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
  Country* current = head;

  if(current == NULL)
  {
    return true;
  }

  return false;

}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) {
  Country *current = new Country;

  current->name = countryName;
  current->next = NULL;

  if(previous == NULL) {
    if(head != NULL){
      current->next = head;
    }
    head = current;

    cout << "adding: " << countryName << " (HEAD)" << endl;
  }
  else {

    current->next = previous->next;
    previous->next = current;

    cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;


  }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {

  Country *current = head;
  Country *temp = new Country;

  if(current == NULL)
  {
    return;
  }
  else
  {

    Country* nam = searchNetwork(countryName);
    if(nam == NULL)
    {
      cout << "Country does not exist." << endl;
      return;
    }

    if(nam == head) {
        //delete HEAD
        temp = head;
        head = head->next;
        delete temp;
        return;
    }

    while(current->next != nam)
    {
      current = current->next;

    }

    current->next = nam->next;

    delete nam;

  }

}


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup() {
  string countryArray[6] = {"United States", "Canada" , "Brazil", "India", "China", "Australia"};

  for(int i = 0; i < 6; i++) {
    Country* previous = searchNetwork(countryArray[i-1]);
    insertCountry(previous, countryArray[i]);
  }

}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName) {

  Country* current = head;

  // while the countryname isn't found
  while(current != NULL)
  {
    // if country is found return pointer to the node
    if(current->name == countryName){
      return current;
    }

    current = current->next;

  }

  return NULL;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork() {

  Country *current = head;
  Country *temp = NULL;

  //if list is empty
  if(current == NULL)
  {
    //empty list
    return;
  }

  while(current != NULL)
  {
    cout << "deleting: " << current->name << endl;

    temp = current->next;
    delete current;
    current = temp;
  }

  head = NULL;

  cout << "Deleted network" << endl;
  //set head to NULL after deleting

}

/*
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */
 void CountryNetwork :: rotateNetwork(int n) {

   if(n < 1)
   {
     cout << "Rotate not possible" << endl;
     return;
   }

   Country *current = head;
   int count = 1;

   if(current == NULL)
     {
         cout << "Linked List is Empty" << endl;
         return;
     }

   while(count < n && current != NULL)
   {
     current = current->next;
     count++;
   }

   if(n > count)
   {
       cout << "Rotate not possible" << endl;
       return;
   }


   Country *nNode = current;

   while(current->next != NULL) {
     current = current->next;
   }

   current->next = head;

   head = nNode->next;

   nNode->next = NULL;

   cout << "Rotate Complete" << endl;

 }
/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork() {

  Country *current = head;
  Country *prev = NULL;
  Country *next = NULL;

  while(current != NULL)
  {
    next = current->next;

    //reverse current node pointer
    current->next = prev;

    //move forward
    prev = current;
    current = next;
  }

  head = prev;

}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
  Country* node = head;
    cout << "== CURRENT PATH ==" << endl;

    if(node == NULL) {
      cout << "nothing in path" << endl;
      cout << "===" << endl;
    }

    while(node != NULL) {
      cout <<  node->name << " -> " ;

      node = node->next;

      if(node == NULL) {
        cout << "NULL" << endl;
        cout << "===" << endl;
        break;
      }
    }
}
