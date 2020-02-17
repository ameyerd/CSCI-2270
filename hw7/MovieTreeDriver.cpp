#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Print the inventory" << endl;
  cout << "2. Delete a movie" << endl;
  cout << "3. Quit" << endl;
}

int main(int argc, char const *argv[]) {

  // stringstream = no commas
  // open file
  // read data
  // insert into separate variables and insert into tree

  ifstream fp;
  fp.open(argv[1]);

  if(fp.is_open())
  {
    MovieTree movie;
    //cout << "open" << endl;

    //cout << "while" << endl;

    string line;

    while(getline(fp , line))
    {
      stringstream ss(line);

      string ranking;
      string title;
      string year;
      string rating;

      getline(fp, ranking,',');
      getline(fp, title,',');
      getline(fp, year,',');
      getline(fp, rating);

      if(rating == "")
      {
        continue;
      }

      //cout << ranking << ":" << title << ":" << year << ":" << rating << endl;

      movie.addMovie(stoi(ranking), title, stoi(year), stof(rating));
    }
    bool run = true;

    while(run)
    {

      //int menuChoice;
      string deleteTitle;
      //here

      displayMenu();
      string choice;

      getline(cin,choice);

      switch(stoi(choice))
      {
        case 1: //print inventory
          movie.printMovieInventory();
          break;

        case 2: // delete movie
          cout << "Enter title:" << endl;
          getline(cin, deleteTitle);

          movie.deleteMovie(deleteTitle);

          break;

        case 3: // print the printMovieInventory
          cout << "Goodbye!" << endl;
          exit(0);

        default:
          run = false;
          break;

      }
    }

    fp.close();
  }
  else
  {
    cout << "Unable to open file." << endl;
  }


  return 0;
}
