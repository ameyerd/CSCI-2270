#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  //write your code
  root = NULL;
}

MovieTree::~MovieTree() {
  //write your code
  delete root;
}

void printMovieHelper(MovieNode *current)
{
  if(current)
  {
    printMovieHelper(current->left);
    //here
    cout << "Movie: " << current->title << " " << current->rating << endl;
    printMovieHelper(current->right);
  }
}

void MovieTree::printMovieInventory() {
   //write your code
   if(root == NULL){
     cout << "Tree is Empty. Cannot print" << endl;
   }
   printMovieHelper(root);
}

MovieNode* createNode(int ranking, string title, int year, float rating)
{
    MovieNode* newNode = new MovieNode(ranking,title,year,rating);
    newNode->title = title;
    newNode->ranking = ranking;
    newNode->year = year;
    newNode->rating = rating;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

MovieNode *addNodeHelper(MovieNode *current, int ranking, string title, int year, float rating)
{
  if(current == NULL)
  {
    return createNode(ranking,title,year,rating);
  }
  else if(current->title < title)
  {
    current->right = addNodeHelper(current->right, ranking, title, year,rating);
  }
  else if(current->title > title)
  {
    current->left = addNodeHelper(current->left, ranking, title, year,rating);
  }
  return current;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  root = addNodeHelper(root, ranking, title, year,rating);
}

MovieNode *findMovieHelper(MovieNode *current, string title)
{
  if(current == NULL){
    return NULL;
  }
  if(current->title == title)
  {
    return current;
  }
  if(current->title > title)
  {
    return findMovieHelper(current->left, title);
  }

  return findMovieHelper(current->right, title);
}

void MovieTree::findMovie(string title) {
  //write your code
  MovieNode *movie = findMovieHelper(root, title);
  if(movie != NULL)
  {
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << movie->ranking << endl;
    cout << "Title  :" << movie->title << endl;
    cout << "Year   :" << movie->year << endl;
    cout << "rating :" << movie->rating << endl;

   }
  else
  {
    cout << "Movie not found." << endl;
  }
}

MovieNode *queryHelper(MovieNode *current, float rating, int year)
{

    if(current)
    {
        if(current->year >= year && current->rating >= rating)
        {
            cout << current->title << "(" << current->year << ") " << current->rating << endl;
        }
    queryHelper(current->left, rating, year);
    queryHelper(current->right, rating, year);

  }

  return NULL;

}

void MovieTree::queryMovies(float rating, int year) {
    //write your code
    // preorder = root, left, right

    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    queryHelper(root, rating, year);


    if (root == NULL)
    {
        cout << "Tree is Empty. Cannot query Movies" << endl;
    }

}

float sumHelper(MovieNode *current)
{

    if(current)
    {
        return current->rating + sumHelper(current->left) + sumHelper(current->right);
    }

    return 0;

}

int countHelper(MovieNode *current)
{
    int count = 1;

    if(current)
    {
        count += countHelper(current->left);
        count += countHelper(current->right);
        return count;
    }

    return 0;
}

void MovieTree::averageRating() {
  //write your code
  int c = countHelper(root);

  float s = sumHelper(root);

  if(c == 0 && s == 0.0)
  {
    cout << "Average rating:0.0" << endl;
  }
  else
  {
      float avg = s / c;
      cout << "Average rating:" << avg << endl;
  }


}
