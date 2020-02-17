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

  MovieTree movie;

  ifstream fp;
  fp.open(argv[1]);

  if(fp.is_open())
  {
    string line;
    int i = 0;
    string rank;
    int MovieRanking;
    stringstream(rank) >> MovieRanking;

    string title;

    string year;
    int MovieYear;
    stringstream(year) >> MovieYear;

    string rating;
    float MovieRating;
    stringstream(rating) >> MovieRating;

    while(!fp.eof())
    {
      stringstream s(line);

      getline(fp,rank);
      // cout <<  rank << endl;
      getline(fp,title);
      // cout << title << endl;
      getline(fp,year);
      // cout << year << endl;
      getline(fp,rating);
      // cout << rating << endl;
      movie.addMovieNode(MovieRanking,title,MovieYear,MovieRating);
    }


    fp.close();
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


  return 0;
}
