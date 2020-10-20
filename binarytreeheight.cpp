//Created by Nevergiv3up
//Height of Binary Tree
//C++ Program 
//Time Complexity O(n)
//The height of a tree is the max number of nodes on the longest path between root and a leaf node in the tree.
#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
  int data; 
  Node* left, *right; 
}; 

//finds the height of the tree recursively
int height(Node* root) 
{ 
  if(root==NULL) 
  {
    return 0; 
  }
  return 1+max(height(root->left),height(root->right)); 
} 

//create a new node of the tree
struct Node* newNode(int data) 
{ 
  struct Node* node = new Node; 
  node->data = data; 
  node->left = node->right = NULL; 
  return (node); 
} 

// main function 
int main() 
{ 
  struct Node* root = newNode(1); 
  root->left = newNode(2); 
  root->right = newNode(3); 
  root->left->left = newNode(4); 
  root->left->right = newNode(5); 
  cout<<height(root)<<endl;

  return 0; 
} 
