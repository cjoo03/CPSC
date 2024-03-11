#include <iostream>
#include <string>
using namespace std;

#ifndef DoublyList_H
#define DoublyList_H

template <class E>
class DoublyListNode{
  public:
    DoublyListNode();
    DoublyListNode(const E e);
    ~DoublyListNode();
    E m_data;
    DoublyListNode<E> *next;
    DoublyListNode<E> *prev;
  private:
};

template <class E>
DoublyListNode<E>::DoublyListNode(){
  next = NULL;
  prev = NULL;
}

template <class E>
DoublyListNode<E>::~DoublyListNode(){
}

template <class E>
DoublyListNode<E>::DoublyListNode(const E e){
  m_data = e;
  next = NULL;
  prev = NULL;
}

template <class E>
class DoublyList{
  public:
    DoublyList();
    ~DoublyList();
    int find(const E e);
    void insertFront(const E e);
    void insertBack(const E e);
    void remove(const E e);
    bool isEmpty() const;
    bool contains(const E e);
    unsigned int getSize();
    void deletePosition(int pos);
    void printList();
    DoublyListNode<E>* getFront() const; 
    E seeFront();
    E removeFront();
    E removeBack();
  private:
    DoublyListNode<E> *m_front;
    DoublyListNode<E> *m_back;
    unsigned int m_size;
};

template <class E>
DoublyList<E>::DoublyList(){
  m_front = NULL;
  m_back = NULL;
  m_size = 0;
}

template <class E>
DoublyList<E>::~DoublyList(){
  while (m_front != NULL){
    DoublyListNode<E> *nextNode = m_front->next;
    delete m_front;
    m_front = nextNode;
  }
}

template <class E>
unsigned int DoublyList<E>::getSize(){
  return m_size;
}

template <class E>
void DoublyList<E>::insertFront(const E e){
  DoublyListNode<E>* node = new DoublyListNode<E>(e);
  if (m_size == 0) {
    m_back = node;
  } else {
    m_front->prev = node;
    node->next = m_front;
  }
  m_front = node;
  ++m_size;
}

template <class E>
E DoublyList<E>::seeFront(){
  return m_front->m_data;
}

template <class E>
DoublyListNode<E>* DoublyList<E>::getFront() const{
  if (isEmpty()){
    cout << "Your list is empty! No elements to retrieve." << endl;
    return NULL;
  } else{
    return m_front;
  }
}

template <class E>
E DoublyList<E>::removeFront() {
  if (!isEmpty()) {
    DoublyListNode<E>* node = m_front;
    E temp = node->data;
    // Only one node in the list
    if (m_front == m_back) {
      m_front = m_back = NULL;
    }
    // More than one node
    else {
      m_front = m_front->next;
      m_front->prev = NULL;
    }
    node->next = NULL;
    delete node;
    --m_size;
    return temp;
  }
  else {
    return E();
  }
}

template <class E>
void DoublyList<E>::insertBack(const E e){
  DoublyListNode<E> *node = new DoublyListNode<E>(e);
  if (m_size == 0) {
    m_front = node;
  } else {
    m_back->next = node;
    node->prev = m_back;
  }
  m_back = node;
  ++m_size;
}

template <class E>
E DoublyList<E>::removeBack(){
  if (isEmpty()) {
    return E();
  }
  DoublyListNode<E>* nodeToRemove = m_back;
  E temp = nodeToRemove->m_data;
  if (m_front == m_back) {
    // The list only contains one node
    m_front = NULL;
    m_back = NULL;
  } else {
    m_back = m_back->prev;
    m_back->next = NULL;
  }
  nodeToRemove->prev = NULL;
  nodeToRemove->next = NULL;
  delete nodeToRemove;
  --m_size;
  return temp;
}


template <class E>
void DoublyList<E>::deletePosition(int pos) {
  if (pos < 0 || pos >= m_size) {
    // Position is out of bounds, do nothing
    return;
  }
  DoublyListNode<E> *curr = m_front;
  DoublyListNode<E> *prev = nullptr;
  // Traverse to the node at the specified position
  for (int i = 0; i < pos; ++i) {
    prev = curr;
    curr = curr->next;
  }
  if (prev == nullptr) {
    // Deleting the first node
    m_front = curr->next;
    if (m_front != nullptr) {
      m_front->prev = nullptr;
    } else {
      m_back = nullptr;
    }
  } else if (curr == m_back) {
    // Deleting the last node
    m_back = prev;
    prev->next = nullptr;
  } else {
    // Deleting a node in the middle
    prev->next = curr->next;
    curr->next->prev = prev;
  }
  curr->next = nullptr;
  curr->prev = nullptr;
  delete curr;
  --m_size;
}

template <class E>
int DoublyList<E>::find(const E e){
  int idx = -1;
  DoublyListNode<E> *curr = m_front;
  while (curr != NULL){
    ++idx;
    if (curr->m_data == e){
      return idx;
    }
    curr = curr->next;
  }
  return -1;
}

template <class E>
void DoublyList<E>::remove(const E key){
  if(isEmpty()){
    cout << "Your list is empty." << endl;
  }
  int position = find(key);
  deletePosition(position);
}

template <class E>
bool DoublyList<E>::isEmpty() const{
    return(m_size == 0);
}

template <class E>
bool DoublyList<E>::contains(const E e){
  if(isEmpty()){
    cout << "Your list is empty! No elements to look for." << endl;
    return false;
  }
  int pos = find(e);
  if (pos == -1){
    return false;
  } else{
    return true;
  }
}

template <class E>
void DoublyList<E>::printList(){
  if (isEmpty()){
    cout << "No data to print." << endl;
    return;
  }
  DoublyListNode<E> *curr = m_front;
  while (curr != NULL) {
    cout << curr->m_data << ", ";
    curr = curr->next;
  }
  cout << endl;
}

#endif