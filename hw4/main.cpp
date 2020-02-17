/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;

    string choice;

    while(choice != "9")
    {

      int menuChoice;
      string countryName;
      string newCountry;
      string previousCountry;
      string delCountry;
      string rotateVal;

      displayMenu();

      getline(cin,choice);

      stringstream(choice) >> menuChoice;

      switch(menuChoice)
      {

        case 1: //build network
          CountryNet.loadDefaultSetup();
          CountryNet.printPath();
          break;

        case 2: // print network path
          CountryNet.printPath();
          break;

        case 3: //add country
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

        case 4: // delete country
          cout << "Enter a country name: " << endl;
          getline(cin, delCountry);

          CountryNet.deleteCountry(delCountry);
          CountryNet.printPath();
          break;

        case 5: // reverse network
          CountryNet.reverseEntireNetwork();
          CountryNet.printPath();
          break;

        case 6: // rotateNetwork
          cout << "Enter the count of values to be rotated: " << endl;
          getline(cin, rotateVal);

          int n;
          stringstream(rotateVal) >> n;

          CountryNet.rotateNetwork(n);
          CountryNet.printPath();
          break;

        case 7: // clear network
          cout << "Network before deletion" << endl;
          CountryNet.printPath();
          CountryNet.deleteEntireNetwork();
          cout << "Network after deletion" << endl;
          CountryNet.printPath();

          break;

        case 8: // quit
          cout << "Quitting... cleaning up path: " << endl;
          CountryNet.printPath();
          CountryNet.deleteEntireNetwork();

          if(CountryNet.isEmpty() == true)
          {
            cout << "Path cleaned" << endl;
          }
          else
          {
            cout << "Error: Path NOT cleaned" << endl;
          }

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
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
