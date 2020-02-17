#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Query movies" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Average Rating of movies" << endl;
  cout << "5. Quit" << endl;
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
    string line;
    int ranking;
    string title;
    int year;
    float rating;

    //cout << "while" << endl;

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

      //cout << ranking << ":" << title << ":" << year << ":" << rating << endl;

      int rank;
      stringstream(ranking) >> rank;
      int movieYear;
      stringstream(year) >> movieYear;
      float rate;
      stringstream(rating) >> rate;

      movie.addMovieNode(rank, title, movieYear, rate);
    }
    string choice;

    while(choice != "6")
    {

      int menuChoice;
      string title;
      string userRating;
      string userYear;

      displayMenu();

      getline(cin,choice);

      stringstream(choice) >> menuChoice;

      switch(menuChoice)
      {
        case 1: //find a movies
          cout << "Enter title:" << endl;
          getline(cin, title);

          movie.findMovie(title);
          break;

        case 2: // query Movies
          cout << "Enter minimum rating:" << endl;
          getline(cin, userRating);

          float rate;
          stringstream(userRating) >> rate;

          cout << "Enter the minimum year:" << endl;
          getline(cin, userYear);

          int year;
          stringstream(userYear) >> year;

          movie.queryMovies(rate, year);
          break;

        case 3: // print the printMovieInventory
          movie.printMovieInventory();
          break;

        case 4: //average raitng
          movie.averageRating();
          break;

        case 5: //quit
          cout << "Goodbye!" << endl;
          exit(0);


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
