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
  bool preSearch(T &value); //used to prevent segmentation fault
  TreeNode<T>* search(T &value);
  bool removeNode(T &key);   //key is ID num
  bool deleteNode(T &key);
  TreeNode<T>* minimumKey(TreeNode<T>* curr);
  TreeNode<T>* getSuccessor(TreeNode<T>* d);

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

        if (current==NULL)
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
bool BST<T>::preSearch(T &value) {
  if (isEmpty()) {
    return false;
  }
  if (isEmpty()) {
    cout << "Tree Empty" << endl;
    return false;
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
          return false;
        }
        current = current->left;
      }
      else if (value > current->data) { //go right
        if (current->right == nullptr) {
          cout << "Member not found" << endl;
          return false;
        }
        current = current->right;
      }
    }
    return true;
  }
}

template <class T>
TreeNode<T>* BST<T>::search(T &value) {
  if (isEmpty()) {
    cout << "Tree Empty" << endl;
    return nullptr;
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
          return nullptr;
        }
        current = current->left;
      }
      else if (value > current->data) { //go right
        if (current->right == nullptr) {
          cout << "Member not found" << endl;
          return nullptr;
        }
        current = current->right;
      }
    }
    return current;
  }
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) {
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;
  while (current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }
  if (successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template <class T>
bool BST<T>::removeNode(T &key) {
  if (isEmpty()) { //root == NULL
    return false;
  }
  //invoke search to determine where exist or not
  TreeNode<T> *parent = nullptr;
  TreeNode<T> *current = root;
  bool isLeftNode = true;
  while (key != current->data) {
    parent = current;
    if (key < current->data) {
      isLeftNode = true;
      current = current->left;
    }
    else{
      isLeftNode = false;
      current = current->right;
    }
    if (current == NULL) {
        return false;
    }
    //at this point we have found our key/value, now we can proceed to deleting this node
    //case: node to be deleted does not have children, AKA a leaf node
    if (current->left == nullptr && current->right == nullptr) {
      if (current == root) {
        root = NULL;
      }
      else if (isLeftNode) {
        parent->left = nullptr;
      }
      else {
        parent->right = nullptr;
      }
    }
    else if (current->right == nullptr) { //case: node to be deleted has 1 child, need to determine which side node is on
      //does not have a right children, must have left child
      if (current == root) {
        root = current->left;
      }
      else if (isLeftNode) {
        parent->left = current->left;
      }
      else {
          //node to be deleted is a right child
        parent->right = current->left;
      }
    }
    else if (current->left == nullptr) { //case: node to be deleted has 1 child, need to determine which side node is on
      //does not have a right children, must have left child
      if (current == root) {
        root = current->right;
      }
      else if (isLeftNode) {
        parent->left = current->right;
      }
      else {
        //node to be deleted is a right child
        parent->right = current->right;
      }
    }
    else {
      //the node to be deleted has two children, at this point we begin to cry
      //we have to find the successor
      TreeNode<T> *successor = getSuccessor(current);
      if (current == root) {
        root = successor;
      }
      else if (isLeftNode) {
        parent->left = successor;
      }
      else {
        parent->right = successor;
      }
      successor->left = current->left;
    }
  }
}

template <class T>
TreeNode<T>* BST<T>::minimumKey(TreeNode<T> *curr) {
  while (curr->left != nullptr) {
    curr = curr->left;
  }
  return curr;
}

template <class T>
bool BST<T>::deleteNode(T &key) {
  TreeNode<T> *parent = nullptr;
  TreeNode<T> *curr = root;
  while (curr != nullptr && curr->data != key) {
    parent = curr;
    if (key < curr->data) {
      curr = curr->left;
    }
    else {
      curr = curr->right;
    }
  }
  if (curr == nullptr) {  //node not found in tree
    return false;
  }
  if (curr->left == nullptr && curr->right == nullptr) { //case no children
    if (curr != root) {
      if (parent->left == curr) {
        parent->left = nullptr;
      }
      else {
        parent->right = nullptr;
      }
    }
    else {
      root = nullptr;
    }
    free(curr);
  }
  else if (curr->left && curr->right) { // case two children
    TreeNode<T> *successor = minimumKey(curr->right);
    T val = successor->data;
    deleteNode(successor->data);
    curr->data = val;
  }
  else {  //case node has only one child
    TreeNode<T> *child = (curr->left)? curr->left: curr->right;
    if (curr != root) {
      if (curr == parent->left) {
        parent->left = child;
      }
      else {
        parent->right = child;
      }
    }
    else {
      root = child;
      free (curr);
    }
  }
}

#endif