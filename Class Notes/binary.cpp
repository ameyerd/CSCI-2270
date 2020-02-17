#include <iostream>
using namespace std;

struct Node
{
  int key;
  Node *left, *right;
};

class BinarySearchTree
{
  private:
    Node *root;
    void printTreeHelper(Node *root, int count);
    Node* insertNodeHelper(Node *r, int k);
    Node* deleteNodeHelper(Node *r, int k);
    Node* searchKeyHelper(Node *root, int k);
  public:
    BinarySearchTree();
    void printTree();
    void searchKey(int k);
    void insertNode(int k);
    Node* createNode(int k);
    void deleteNode(int k);
};

BinarySearchTree::BinarySearchTree()
{
  root = NULL; // nullptr is not an int, NULL can be
}

//print
void BinarySearchTree::searchKeyHelper(Node *root, int k)
{
  if(root)
  {
    if(root->key == k)
    {
      return root;
    }
    if (root->key < k)
    {
      return searchKeyHelper(root->right, k);
    }
    else if (root->key > k)
    {
      return searchKeyHelper(root->left, k);
    }
    // for(int i = 0; i < count; i++)
    // {
    //   cout << "\t";
    // }
    // cout << "printTree(" << root->key << "," << count << ")" << endl;
    // // left subtree
    // printTreeHelper(root->left, ++count);
    // // middle node (parent)
    // cout << root->key << " ";
    // //right subtree
    // printTreeHelper(root->right, ++count);
  }

  else{
    cout << "Key is not in tree :(" << endl;
    return NULL;
  }
}

void BinarySearchTree::searchKey(int k)
{
  Node* ret = searchKeyHelper(root, 0);
  if (ret) //ret is not NULL
  {
    cout << ret->key << " has been found!" << endl;
  }

}

// insert
Node* BinarySearchTree::createNode(int k)
{
  Node *newNode = new Node;
  newNode->key = k;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}
void BinarySearchTree::insertNode(int k)
{
  root = insertNodeHelper(root, k);
}

Node* BinarySearchTree::insertNodeHelper(Node *r, int k)
{
  // insert at the head
  if (r == NULL)
  {
    // cout << "Inserting: " << k << " at the head!" << endl;
    r = createNode(k);
  }

  else if (r->key < k) // insert to the RIGHT
  {
    r->right = insertNodeHelper(r->right, k);
  }
  else
  {
    r->left = insertNodeHelper(r->left, k);
  }

  return r;
}

//delete

void deleteNode(int k)
{
  root = deleteNodeHelper(root, k);
}

Node* deleteNodeHelper(Node *r, int k)
{
  Node *toDelete = searchKey(k);
  if(!toDelete)
  {
    cout << "Node was not in the tree" << endl;
    return r;
  }

  // 3 cases
  // if (toDelete->right == NULL && toDelete->left == NULL)
  if(toDelete->right == toDelete->left) // Node toDelete has no children
  {
    delete toDelete;
    r = NULL;
  }
  else if(toDelete->right == NULL || toDelete->left == NULL) // Node has two children
  {
    if(!toDelete->right)
    {
      r->right = deleteNodeHelper(r->right, k);
    }
    else if (!toDelete->left)
    {
      r->left = deleteNodeHelper(r->left, k);
    }
  }

  else()
  {

  }




  return r;
}

int main()
{
  BinarySearchTree bst;

  bst.insertNode(10);
  bst.searchKey();
  bst.printTree();
  bst.insertNode(12);
  bst.printTree();
  bst.insertNode(5);
  bst.printTree();
  bst.insertNode(4);
  bst.printTree();

  // bst.insertNode(6);
  // bst.printTree();
  // bst.insertNode(13);
  // bst.printTree();
  // bst.insertNode(17);
  // bst.printTree();

  return 0;
}
