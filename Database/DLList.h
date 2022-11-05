/*
Kaitlyn Vetica
CPSC 350-03
Header and template file for DLList class. Defines the methods and private members of 
a doubly linked list. Uses ListNodes as the pointers that are contained in the List. 
*/

#include "ListNode.h"


#ifndef DLList_h
#define DLList_h

template <typename E>
class DLList{
private:
  ListNode<E>* head; // pointer to front of list
  ListNode<E>* tail; // pointer to back of list
  int size; // number of elements in list

public:
  DLList();
  ~DLList();
  void insertFront(E item);
  void insertBack(E item);
  E removeFront();
  E removeBack();
  E peekFront();
  E peekBack();
  int length();
  bool isEmpty();
  bool find(E item);
  E removeNode(E item);
};

/*
Constructor for DLList.
*/
template <typename E>
DLList<E>::DLList(){
  head = nullptr;
  tail = nullptr;
  size = 0;
}

/*
Destructor for DLList.
*/
template <typename E>
DLList<E>::~DLList(){
  ListNode<E>* temp = head;
  while(head != nullptr){
    temp = head;
    head = head->next;
    delete temp;
  }
}

/*
insertFront function
Inserts a list node to the front of the list.
@param E item - Item to be inserted at the front 
*/
template <typename E>
void DLList<E>::insertFront(E item){
  ListNode<E>* temp = new ListNode<E>(item);
  if(size == 0){
    tail = temp;
  }
  else{
    head->prev = temp;
    temp->next = head;
  }
  head = temp;
  size++;
}

/*
insertBack function
Inserts a list node to the back of the list.
@param E item - Item value to be inserted at the back
*/
template <typename E>
void DLList<E>::insertBack(E item){
  ListNode<E>* temp = new ListNode<E>(item);
  if(size == 0){
    head = temp;
  }
  else{
    tail->next = temp;
    temp->prev = tail;
  }
  tail = temp;
  size++;
}

/*
removeFront function
Removes a list node from the front of the list.
@return E - Item value at front.
*/
template <typename E>
E DLList<E>::removeFront(){
  ListNode<E>* temp = head;
  if(head->next == nullptr){
    tail = nullptr;
  }
  else{
    head->next->prev = nullptr;
    head = head->next;
  }
  E item = temp->element;
  temp->next = nullptr;
  delete temp;
  if(size > 0)
    size--;
  return item;
}


/*
removeBack function
Removes a list node from the back of the list.
@return E - item value at back.
*/
template <typename E>
E DLList<E>::removeBack(){
  ListNode<E>* temp = tail;
  if(tail->prev = nullptr){
    head = nullptr;
  }
  else{
    tail->prev->next = nullptr;
    tail = tail->prev;
  }
  E item = temp->element;
  temp->prev = nullptr;
  delete temp;
  if(size > 0)
    size--;
  return item;
}

/*
peekFront function
Returns the data value at front of list
@return E - item value at front.
*/
template <typename E>
E DLList<E>::peekFront(){
  return head->element;
}

/*
peekBack function
Returns the data value at the back of list
@return E - item value at back.
*/
template <typename E>
E DLList<E>::peekBack(){
  return tail->element;
}

/*
length function 
Returns the size of the list.
@return int - size of list.
*/
template <typename E>
int DLList<E>::length(){
  return size;
}


/*
isEmpty function
Returns if list is empty or not by checking size.
@return bool - Returns true if empty, returns false if not
*/
template <typename E>
bool DLList<E>::isEmpty(){
  return (size==0);
}

/*
find function 
Finds a node in a linked list that matches the parameter item 
@param E item - Item to find in list 
@return bool - Returns true if found, returns false if not 
*/
template <typename E>
bool DLList<E>::find(E item){
  ListNode<E>* temp = head;
  while(temp != nullptr){
    if(temp->element == item){
      return true;
      break;
    }
    temp = temp->next;
  }
  return false;
}

/*
removeNode function 
Removes given node in list 
@param E item - Item to remove from list 
@return E - Returns the removed item 
*/
template <typename E>
E DLList<E>::removeNode(E item){
  ListNode<E>* temp = head;
  if(isEmpty()){
    return E();
  }
  while(temp->element != item){
    temp = temp->next;
    if(temp == nullptr){
      return E();
    }
  }
  if(temp != head && temp != tail){
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
  }

  if(temp == head){
    head = temp->next;
    // head->prev = nullptr;
  }

  if(temp == tail){
    tail = temp->prev;
    // tail->next = nullptr;
  }

  temp->next = nullptr;
  temp->prev = nullptr;

  E removedNode = temp->element;
  size--;
  delete temp;
  return removedNode;
}


#endif