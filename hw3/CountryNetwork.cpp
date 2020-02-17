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
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
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
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
  string countryArray[6] = {"United States", "Canada" , "Brazil", "India", "China", "Australia"};

  for(int i = 0; i < 6; i++) {
    Country* previous = searchNetwork(countryArray[i-1]);
    cout << "Insert"
    insertCountry(previous, countryArray[i]);
  }


}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{

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
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
  Country* current = head;

  if(current == NULL)
  {
    cout << "Empty list" << endl;
  }

  else {

    while(current != NULL)
    {
      Country* rec = searchNetwork(receiver);
      if(rec == NULL) {
        cout << "Country not found" << endl;
        break;
      }

      if(current->name == receiver) {

        current->message = message;
        current->numberMessages = current->numberMessages + 1;

        cout << current->name << " [# messages received: " << current->numberMessages << "] received: " << current->message << endl;

        break;
      }
      else {
        current->message = message;
        current->numberMessages = current->numberMessages + 1;

        cout << current->name << " [# messages received: " << current->numberMessages << "] received: " << current->message << endl;
      }

      current = current->next;
    }

  }

}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
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
