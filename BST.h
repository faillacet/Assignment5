#ifndef BST_H
#define BST_H

#include "TreeNode.h"
using namespace std;

template <class T>
class BST{
public:
  BST();
  virtual ~BST();
  void insert(T &value);
  bool getRoot();
  void contains(T &value);  //AKA search
  TreeNode<T>* deleteNode(int key);   //key is ID num

  TreeNode<T>* getSuccessor(TreeNode<T>* d);
  bool deleteRec();

  TreeNode<T>* getMin();
  TreeNode<T>* getMax();
  bool isEmpty();
  void printTree();
  void recPrint(TreeNode<T> *d);
  void pushTree(string input);
  void recPush(TreeNode<T> *d, ofstream &myFile);

private:
  TreeNode<T> *root;
};

template <class T>
BST<T>::BST() //default constructor
{
  root = NULL;  //empty tree
}

template <class T>
BST<T>::~BST()
{
  //iterate and delete
  //need to add here
}

template <class T>
void BST<T>::printTree()
{
  recPrint(root);
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node)
{
  if (node==NULL)
    return;
  else{
    recPrint(node->left);
    node->printInfo();
    recPrint(node->right);
  }
}

template <class T>
void BST<T>::pushTree(string input) {
  ofstream myFile(input);
  recPush(root, myFile);
  myFile.close();
}

template <class T>
void BST<T>::recPush(TreeNode<T> *node, ofstream &myFile) {
  if (node==NULL){
    return;
  }
  else {
    recPush(node->left, myFile);
    node->pushToFile(myFile);
    recPush(node->right, myFile);
  }
}

template <class T>
bool BST<T>::isEmpty()
{
  return (root == NULL);
}

template <class T>
void BST<T>::insert(T &value)
{
  // check if value exists, use contains(), if DNE then continue
  TreeNode<T> *node = new TreeNode<T>(value);   //key is now set to  value
  if(isEmpty())   //empty tree
  {
    root = node;
  }
  else    //not an empty tree, need to find insertion point
  {
    TreeNode<T> *current = root;
    TreeNode<T> *parent;   //empty node

    while(true)
    {
      parent = current;

      if (node->data < current->data)
      {
        current = current->left;   //going left

        if(current==NULL)  //we found the insertion point for new node
        {
          parent->left = node;
          break;
        }
        //else keep looping
      }
      else //going right
      {
        current = current->right;

        if(current==NULL)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::getRoot()
{
  return root;
}

template <class T>
void BST<T>::contains(T &value) {
  if (isEmpty()) {
    cout << "Tree Empty" << endl;
    return;
  }
  else {
    TreeNode<T> *current = root;
    TreeNode<T> *parent = nullptr;
    while (current->data != value)
    {
      parent = current;
      if (value < current->data) {  //going left
        if (current->left == nullptr) {
          cout << "Member not found" << endl;
          return;
        }
        current = current->left;
      }
      else if (value > current->data) { //go right
        if (current->right == nullptr) {
          cout << "Member not found" << endl;
          return;
        }
        current = current->right;
      }
    }
    cout << "Member found: " << endl;
    current->printInfo();
  }
  return;
}

template <class T>
TreeNode<T>* BST<T>::deleteNode(int key) { //key is student ID in this case
  if (root==NULL) {
    return root;
  }
  if (key < root->data) {
    root->left = deleteNode(key);
  }
  else if (key > root->data) {

  }
  else {

  }

  
}

#endif