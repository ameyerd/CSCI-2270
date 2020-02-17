#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

MovieTree::MovieTree()
{
  root = NULL;
}

// bool isEmpty(LLMovieNode *root)
// {
//   if(root == NULL) return true;
//
//   return false;
// }
//
// LLMovieNode *deleteMovieAtIndex(LLMovieNode *current, string title)
// {
//   if(head == NULL) return NULL;
//
//   if (title == current->head->title)
//   {
//     LLMovieNode *temp;
//     temp = curent->head;
//     current->head = current->head->next;
//     delete temp;
//   }
//
//   LLMovieNode *pres = current;
//   LLMovieNode *prev = NULL;
//
//   while(current)
//   {
//     prev = pres;
//     pres = pres->next;
//   }
//
//   prev->next = pres->next;
//   delete prev;
//
//   return current;
// }
//
// void deleteTree(TreeNode *current)
// {
//   while(!isEmpty(current->head)){
//       current->head = deleteMovieAtIndex(current->head, current->head->title);
//     }
// }
//
// MovieTree::~MovieTree()
// {
//   deleteTree(root);
//   root = NULL;
// }
//ehwweirerewwrewrwrwrew
// void deleteTree(TreeNode *current){
//   if(current != NULL)
//   {
//    deleteTree(current->leftChild);
//    deleteTree(current->rightChild);
//
//    LLMovieNode* temp = current->head;
//    while (temp) {
//      current->head = current->head->next;
//      delete temp;
//      temp = current->head;
//    }
//
//    delete current;
//
//   }
// }
//
// MovieTree::~MovieTree() {
//   deleteTree(root);
// }

void deleteTree(TreeNode *current){
  if(current != NULL)
  {
   deleteTree(current->leftChild);
   deleteTree(current->rightChild);

   LLMovieNode* temp = current->head;
   while (temp) { //delete LL nodes
     current->head = current->head->next;
     delete temp;
     temp = current->head->next;
   }

   delete current; //delete tree node

  }
}

MovieTree::~MovieTree() {
  deleteTree(root);
}

void printMovieHelper(TreeNode *current)
{

  if(current)
  {
    printMovieHelper(current->leftChild);

    cout << "Movies starting with letter: " << current->titleChar << endl;
    LLMovieNode *m = current->head;

    while(m)
    {
      cout << " >> " << m->title << " " << m->rating << endl;

      m = m->next;
    }

    printMovieHelper(current->rightChild);
  }

}

void MovieTree::printMovieInventory()
{
  //print every movie in alphabetical order
  // For TreeNode t and LLMovieNode m:
  // for every TreeNode (t) in the tree
  // cout << "Movies starting with letter: " << t->titleChar << endl; // for every LLMovieNode (m) attached to t
  // cout << " >> " << m->title << " " << m->rating << endl;

  printMovieHelper(root);

}

TreeNode *addMovieHelper(TreeNode* current, LLMovieNode *m)
{
  if(current == NULL)
  {
    current = new TreeNode;
    current->titleChar = m->title[0];
    current->head = m;
    current->leftChild = NULL;
    current->rightChild = NULL;
    current->parent = NULL;
    return current;
  }
  if(current->titleChar < m->title[0])
  {
    TreeNode* leftN = addMovieHelper(current->leftChild, m);

    current->leftChild = leftN;
    leftN->parent = current;
  }
  else if(current->titleChar > m->title[0])
  {
    TreeNode* rightN = addMovieHelper(current->rightChild, m);

    current->rightChild = rightN;
    rightN->parent = current;
  }
  else if(current->titleChar == m->title[0])
  {
    //LLMovieNode *insertN = current->head;
    LLMovieNode *pres = current->head;
    LLMovieNode *prev = NULL;
    bool hi = false;
    if (pres->title > m->title)
    {
      m->next = pres;
      current->head = m;
      hi = true;
    }
    while(pres->next != NULL)
    {
      if (pres->title > m->title)
      {
        m->next = pres;
        prev->next = m;
        hi = true;
        break;
      }

      prev = pres;
      pres = pres->next;

    }

    if (hi == false)
    {
      pres->next = m;
      m->next = NULL;
    }



  }
  return current;
}

void MovieTree::addMovie(int ranking, string title, int year, float rating) {
  //write your code
  LLMovieNode* m = new LLMovieNode(ranking, title, year, rating);

  root = addMovieHelper(root, m);
}


TreeNode *deleteMovieHelper(TreeNode *current, string title)
{

  if(current == NULL)
  {
    cout << "Movie: " << title << " not found, cannot delete." << endl;
    return current;
  }

  if(title.at(0) < current->titleChar)
  {
    current->leftChild = deleteMovieHelper(current->leftChild, title);
  }
  else if(title.at(0) > current->titleChar)
  {
    current->rightChild = deleteMovieHelper(current->rightChild, title);
  }
  else if(title.at(0) == current->titleChar)
  {
    LLMovieNode *currNode = current->head;
    LLMovieNode *prev = NULL;

    while(currNode && currNode->title.compare(title) != 0)
    {
      prev = currNode;
      currNode = currNode->next;
    }

    if(currNode == NULL)
    {
      cout << "Movie: " << title << " not found, cannot delete." << endl;
      return current;
    }
    if(prev == NULL && current->head->next != NULL)
    {
      current->head = current->head->next;
      return current;
    }

    if(prev != NULL && currNode != NULL)
    {
      prev->next = currNode->next;
      return current;
    }

    if(current->leftChild == NULL && current->rightChild == NULL)
    {
      delete current;
      current = NULL;
    }
    else if (current->leftChild == NULL)
    {
      TreeNode *temp = current;
      current->rightChild->parent = current->parent;
      current = current->rightChild;
      delete temp;
    }
    else if (current->rightChild == NULL)
    {
      TreeNode *temp = current;
      current->leftChild->parent = current->parent;
      current = current->leftChild;
      delete temp;
    }
    else
    {
      TreeNode* min = current->rightChild;
      while (min->leftChild != NULL)
      {
          min = min->leftChild;
      }
      current->head = min->head;
      current->titleChar = min->titleChar;
      current->rightChild = deleteMovieHelper(current->rightChild, min->head->title);
    }

  }

  return current;
}

void MovieTree::deleteMovie(string title)
{
  root = deleteMovieHelper(root, title);
}
