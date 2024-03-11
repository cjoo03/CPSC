#include <iostream>
#include <string>

using namespace std;

#ifndef BST_H
#define BST_H

template <class E>
class TreeNode{
    public:
      TreeNode();
      virtual ~TreeNode();
      TreeNode(const TreeNode<E> &other);
      TreeNode (E k); 
      void operator=(const TreeNode<E> &other);
      bool operator==(const TreeNode<E> &other);
      E key;
      TreeNode<E> *left;
      TreeNode<E> *right;
};

template <class E>
TreeNode<E>::TreeNode(){
  left = NULL;
  right = NULL;
}

template <class E>
TreeNode<E>::~TreeNode(){
}

template <class E>
TreeNode<E>::TreeNode(const TreeNode<E> &other){
  left = NULL;
  right = NULL;
  key = other->key;
}


template <class E>
TreeNode<E>::TreeNode(E k){
  left = NULL;
  right = NULL;
  key = k;
}


//Copy the value of one node to another.
template <class E>
void TreeNode<E>::operator=(const TreeNode<E> &other){
  left = NULL;
  right = NULL;
  key = other->key;
}


// Determines whether this node is equal to another node based on their key values.
template <class E>
bool TreeNode<E>::operator==(const TreeNode<E> &otherNode){
  return (key == otherNode.key);
}

template <class E>
class BST {
public:
    BST(); // default constructor
    virtual ~BST(); // destructor

    bool contains(E value); // returns true if the BST contains a node with value as the key
    bool deleteNode(E value); // deletes the node with value as the key and returns true if successful
    bool isEmpty() const; // returns true if the BST is empty

    TreeNode<E>* getSuccessor(TreeNode<E>* nodeToDelete); // returns the successor of d (used in deleteNode)
    TreeNode<E>* getRoot() const; // returns the root of the BST
    TreeNode<E>* getNode(E value); // returns the node with value as the key (if it exists)

    void printTree(); // prints the entire BST
    void recPrint(TreeNode<E> *node); // recursively prints the subtree rooted at node
    void deleteRecursive(TreeNode<E> *node); // recursively deletes all nodes in the subtree rooted at node
    void copy(const BST<E>& otherTree); // copies the contents of the other tree into this BST
    void operator=(const BST<E>& otherTree); // assigns the contents of the other tree to this BST
    void clear(); // deletes all nodes in the BST
    void insert(E value); // inserts a new node with value as the key

    int getSize();  // returns the number of nodes in the BST
private:
    TreeNode<E> *root; // pointer to the root node of the BST
    friend class TreeNode<E>; // allows access to private members by TreeNode
    void recCopy(const TreeNode<E> *node); // recursively copies the subtree rooted at node
    int m_size; // the number of nodes in the BST
};


template <class E>
BST<E>::BST(){
  root = NULL; 
  int m_size = 0;
}

template <class E>
BST<E>::~BST(){
  deleteRecursive(root);
}

template <class E>
void BST<E>::deleteRecursive(TreeNode<E> *node){
  if(node == NULL){
    return; //ends function
  }
  deleteRecursive(node->left);
  delete node;
  deleteRecursive(node->right);
}

//The copy method first deletes a tree and then copies another tree from its root
template <class E>
void BST<E>::copy(const BST<E>& otherTree){
  deleteRecursive(root);
  recCopy(otherTree.getRoot());
}

template <class E>
void BST<E>::operator=(const BST<E>& otherTree){
  copy(otherTree);
}


template <class E>
void BST<E>::clear(){
  if (root != NULL) {
    deleteRecursive(root);
    root = NULL;
    m_size = 0;
  }
}


template <class E>
void BST<E>::printTree(){
  recPrint(root);
}

template <class E>
void BST<E>::recPrint(TreeNode<E>* node){
  if (node == nullptr) {
      return;
  }
  recPrint(node->left);
  std::cout << node->key << std::endl;
  recPrint(node->right);
}


template <class E>
bool BST<E>::isEmpty() const{
  if (root == NULL) {
      return true;
   } else {
      return false;
  }
}

template <class E>
void BST<E>::insert(E value){
  if (contains(value)) {
    return; // value already exists in tree
  }
  TreeNode<E> *node = new TreeNode<E>(value);
  if (isEmpty()) {
    root = node;
    } else {
      TreeNode<E> *current = root;
      TreeNode<E> *parent;
        while (true) {
            parent = current;
            if (value < current->key) {
                current = current->left;
                if (current == NULL) {
                    parent->left = node;
                    break;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = node;
                    break;
                }
            }
        }
    }
    m_size++;
}

template <class E>
bool BST<E>::contains(E value){
  TreeNode<E>* current = root;
  while (current != NULL){
    if (current->key == value){
      return true;
      }
    else if (value < current->key){
      current = current->left;
    } else{
      current = current->right;
    }
  }
  return false;
}


template <class E>
void BST<E>::recCopy(const TreeNode<E> *node){
  if (node != nullptr){
    recCopy(node->left);
    insert(node->key);
    recCopy(node->right);
  }
}

template <class E>
bool BST<E>::deleteNode(E value){
  if (isEmpty()) {
    return false;
  }
  // Find the node to be deleted
  TreeNode<E>* parent = nullptr;
  TreeNode<E>* current = root;
  bool isLeft = false;

  while (current != nullptr) {
    if (value == current->key) {
      break;
    }
    parent = current;
    if (value < current->key) {
      current = current->left;
      isLeft = true;
    } else {
      current = current->right;
      isLeft = false;
    }
  }
  if (current == nullptr) {
    return false;  // Node not found
  }

  // Case 1: Node has no children
  if (current->left == nullptr && current->right == nullptr) {
    if (current == root) {
      root = nullptr;
    } else if (isLeft) {
      parent->left = nullptr;
    } else {
      parent->right = nullptr;
    }
    delete current;
  }

  // Case 2: Node has one child
  else if (current->left == nullptr || current->right == nullptr) {
    TreeNode<E>* child = (current->left != nullptr) ? current->left : current->right;
    if (current == root) {
      root = child;
    } else if (isLeft) {
      parent->left = child;
    } else {
      parent->right = child;
    }
    delete current;
  }

  // Case 3: Node has two children
  else {
    TreeNode<E>* successor = getSuccessor(current);
    successor->left = current->left;
    if (current == root) {
      root = successor;
    } else if (isLeft) {
      parent->left = successor;
    } else {
      parent->right = successor;
    }
    delete current;
  }

  m_size--;
  return true;
}

template <class E>
TreeNode<E>* BST<E>::getSuccessor(TreeNode<E>* nodeToDelete){
  // Initialize successor's parent and successor
  TreeNode<E>* sp = nodeToDelete; 
  TreeNode<E>* successor = nodeToDelete->right;

  // Find the successor by moving to the leftmost node of the right subtree
  while (successor->left != NULL){
    sp = successor;
    successor = successor->left;
  }

  // Rearrange pointers if necessary
  if (successor != nodeToDelete->right)
  {
    sp->left = successor->right;
    successor->right = nodeToDelete->right;
  }

  return successor;
}



template <class E>
TreeNode<E>* BST<E>::getRoot() const{
  return root;
}


template <class E>
TreeNode<E>* BST<E>::getNode(E value){
  if(isEmpty() || !(contains(value))){
    return nullptr;
  }
  
  TreeNode<E> *current = root;
  while (current != nullptr){
    if (current->key == value){
      return current;
    }
    else if (value < current->key){
      current = current->left;
  } else {
      current = current->right;
    }
  }
  return nullptr;
}


template <class E>
int BST<E>::getSize(){
  return m_size;
}

#endif