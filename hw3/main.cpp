/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;

    string choice;

    while(choice != "6") {
      int menuChoice;
      string countryName;
      string message;
      string newCountry;
      string previousCountry;


      displayMenu();

      //cin.ignore();
      getline(cin, choice);

      stringstream(choice) >> menuChoice;

      switch(menuChoice) {

        case 1:
          CountryNet.loadDefaultSetup();
          CountryNet.printPath();
          break;

        case 2:
          CountryNet.printPath();
          break;

        case 3:
          cout << "Enter name of the country to receive the message: " << endl;
          getline(cin, countryName);

          cout << "Enter the message to send: " << endl;
          getline(cin, message);

          cout << endl;

          CountryNet.transmitMsg(countryName, message);
          // do the country not found thing for ex. japan
          break;

        case 4:
          cout << "Enter a new country name: " << endl;
          getline(cin, newCountry);
          newCountry[0] = toupper(newCountry[0]);

          cout << "Enter the previous country name (or First): " << endl;
          getline(cin, previousCountry);


          if(previousCountry == "First" || previousCountry == "first") {
            //add to the head of the list
            CountryNet.insertCountry(NULL, newCountry);
            CountryNet.printPath();
            break;
          }
          else if (CountryNet.searchNetwork(previousCountry) == NULL){
            //if previousCountry is not found
            while(CountryNet.searchNetwork(previousCountry) == NULL) {
              cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
              getline(cin, previousCountry);

              if(previousCountry == "First" || previousCountry == "first") {
                CountryNet.insertCountry(NULL, newCountry);
                CountryNet.printPath();
                break;

              }

              CountryNet.insertCountry(CountryNet.searchNetwork(previousCountry), newCountry);
              CountryNet.printPath();
            }

          }
          else{
            //insert country
            // Country* previous = CountryNet.searchNetwork(previousCountry);
            CountryNet.insertCountry(CountryNet.searchNetwork(previousCountry), newCountry);
            CountryNet.printPath();
          }

          break;

        case 5:
          cout << "Quitting..." << endl;
          cout << "Goodbye!" << endl;
          exit(0);
      }

    }
    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
