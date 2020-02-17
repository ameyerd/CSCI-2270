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


void deleteTree(TreeNode *current){
  if(current != NULL)
  {
   deleteTree(current->leftChild);
   deleteTree(current->rightChild);

   LLMovieNode* temp = current->head;
   while (temp)
   {
     current->head = current->head->next;
     delete temp;
     temp = current->head->next;
   }

   delete current;

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

// --------------------ADD MOVIE--------------------------------

//createNode helper function
TreeNode* createNode(TreeNode *newNode, LLMovieNode *m)
{
    newNode = new TreeNode;
    newNode->head = m;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->titleChar = m->title[0];
    return newNode;
}

// helper function to add movie into the linked list at specific node
LLMovieNode *addMovieLLHelper(TreeNode *Node, LLMovieNode *m)
{
  // if list is empty aka, head is null
  if(Node->head == NULL)
  {
    Node->head = m;
    Node->leftChild = NULL;
    Node->rightChild = NULL;
    return m;
  }

  LLMovieNode *pres = Node->head;
  LLMovieNode* prev = Node->head;

  while(prev->title < m->title)
  {
    if (pres->title > m->title)
    {
      //insert
      m->next = pres;
      prev->next = m;
      return Node->head;
    }
    prev = pres;
    pres = pres->next;
  }


    pres->next = m;
    m->next = NULL;


  return Node->head;

}

// helper function to find the node in the binary tree (char)
TreeNode *addMovieHelper(TreeNode *current, LLMovieNode *m)
{
  if(current == NULL)
  {
    return createNode(current, m);
  }
  else if(current->titleChar < m->title[0])
  {
    current->rightChild = addMovieHelper(current->rightChild, m);
  }
  else if(current->titleChar > m->title[0])
  {
    current->leftChild = addMovieHelper(current->leftChild, m);
  }
  if(current->titleChar == m->title[0])
  {
    current->head = addMovieLLHelper(current, m);
  }

  return current;
}


void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
  //call helper function
  LLMovieNode *m = new LLMovieNode(ranking, title, year, rating);
  root = addMovieHelper(root, m);

}

//------------------------------------------------------------

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
