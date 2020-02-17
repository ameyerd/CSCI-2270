#include <iostream>
#include "BST.hpp"
using namespace std;

int findSum(Node * root, int depth)
{
    if(root != NULL)
    {
        int rightSum = findSum(root->right, depth + 1);
        int leftSum = findSum(root->left, depth + 1);
        cout << root->key;
        if (depth != 0)
        {
            cout << " ";
        }
        return rightSum + leftSum + root->key;
    }
    else
       return 0;
}

void change(Node* node)
{
  if(node == NULL)
  {
    return;
  }
  else
  {
    Node* temp;

    change(node->left);
    change(node->right);

    temp = node->left;
    node->left = node->right;
    node->right = node->left;
  }
}


int main (int argc, char* argv[]){
  cout<<"Creating tree"<<endl;
  BST tree;


  tree.addNode(4); //left child to 5
  tree.addNode(2); //left child to 1
  tree.addNode(7); //right child to 2
  tree.addNode(1); //right child to 5
  tree.addNode(3); //right child of 7
  tree.addNode(6); // left child of 10
  tree.addNode(9); // left child of 7

  cout<<"----------------Intial tree is ---------------"<<endl<<endl;
  tree.print2DUtil(1);

  cout<<"----------------Inorder traversal of the tree is ---------------"<<endl<<endl;
  tree.printTree();

  // cout << "----sum----" << endl<<endl;
  Node* root = tree.getRoot();
  // findSum(root,0);

  cout << "-----change-----" <<endl<<endl;
  change(root);

  // cout<<"Enter the range for nodes which need to be removed"<<endl;
  // cout<<"lower bound?"<<endl;
  // int lower;
  // cin>>lower;
  // cout<<endl;
  // cout<<"upper bound?"<<endl;
  // int upper;
  // cin>>upper;
  // cout<<endl;
  //
  // //SILVER TODO - Complete the TODOs in deleteNode() function which is called within removeRange() function
  // tree.removeRange(lower,upper);
  //
  // cout<<"----------------Final tree after deletion is ---------------"<<endl<<endl;
  // tree.print2DUtil(1);
  //
  // cout<<"----------------Inorder traversal of the tree after deletion ---------------"<<endl<<endl;
  // tree.printTree();
  //
  //
  // // GOLD TODO  - Complete this function
  // cout<< tree.isValidBST() << endl;

}
