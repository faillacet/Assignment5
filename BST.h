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
  bool contains(int value);  //AKA search
  bool removeNode(T &value);   //T or F if the node was deleted

  TreeNode<T>* getSuccessor(TreeNode<T>* d);
  bool deleteRec();

  TreeNode<T>* getMin();
  TreeNode<T>* getMax();
  bool isEmpty();
  void printTree();
  void recPrint(TreeNode<T> *d);
  void fileTree();
  void recFile(TreeNode<T> *d);

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
bool BST<T>::contains(int value)
{
  if(isEmpty())
    return false;
  else  //not empty tree
  {
    TreeNode<T> *current = root;

    while(current->data != value)
    {
      if(value < current->data)  //going left
        current = current->left;
      else
        current = current->right;
      if(current == NULL)   //we did not find it, DNE
        return false;
    }
    cout << current->key.printInfo() << endl;
  }
  return true;
}



template <class T>
void BST<T>::fileTree()
{
  recFile(root);
}

// template <class T>
// void BST<T>::recFile(TreeNode<T> *node)
// {
//   if (node==NULL)
//     return;
//   else{
//     recFile(node->left);
//     file_ << node->key.printInfo() << endl;
//     recFile(node->right);
//   }
// }


template <class T>
bool BST<T>::removeNode(int k){
    if(isEmpty()) //root == NUL
      return false;

    //invoke search to determine where exist or not

    TreeNode *parent = NULL;
    TreeNode *current = root;
    bool isLeftNode = true;

    while(current->key != k){
      parent = current;

      if(k < current->key){
        isLeftNode = true;
        current = current->left;
      }
      else{
        isLeftNode = false;
        current = current->right;
      }

      if(current == NULL)
        return false;
    }

    //at this point we have found our key/value, now we can proceed to deleting this node

    //case: node to be deleted does not have children, AKA a leaf node
    if(current->left == NULL && current->right == NULL){
        if(current == root)
          root = NULL;
        else if(ifLeftNode){
          parent->left = NULL;
        }
        else{
          parent->right = NULL;
        }
    }
    //case: node to be deleted has 1 child, need to determine which side node is on
    else if(current->right == NULL){
      //does not have a right children, must have left child
      if(current == root)
          root = current->left
      else if(isLeftNode){
          parent-left = current->left;
      }
      else{
          //node to be deleted is a right child
          parent->right = current->left;
      }

      //case: node to be deleted has 1 child, need to determine which side node is on
      else if(current->left == NULL){
        //does not have a right children, must have left child
        if(current == root)
            root = current->right
        else if(isLeftNode){
            parent-left = current->right;
        }
        else{
            //node to be deleted is a right child
            parent->right = current->right;
        }

        else{
            //the node to be deleted has two children, at this point we begin to cry
            //we have to find the successor

            TreeNode *successor = getSuccessor(current);

            if(current == root)
              root = successor;
            else if(isLeftNode){
              parent->left = successor;
            }
            else{
              parent->right = successor;
            }
            successor->left = current->left;
        }
}

TreeNode* BST::getSuccessor(TreeNode *d)
{

  TreeNode *sp = d;
  TreeNode *successor = d;
  TreeNode *current = d->right;

  while(current != NULL){

    sp = successor;
    successor = current;
    current = current->left;

  }

  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;

}

#endif
