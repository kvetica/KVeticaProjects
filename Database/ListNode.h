/*
Kaitlyn Vetica
CPSC 350-03
Header and template file for ListNode class. Defines the methods and private members of 
a ListNode object. ListNodes and its pointers are used in and DLList
*/

#ifndef ListNode_h
#define ListNode_h

template <typename E>
class ListNode{
public:
  E element;
  ListNode* prev; // pointer to previous node
  ListNode* next; // pointer to next node

  /*
  Constructor initializes prev and next pointers
  */
  ListNode(){
    prev = nullptr;
    next = nullptr;
  }

  /*
  Overloaded constructor initializes prev and next pointers and sets value of element
  @param elemVal: data value to be added to node
  */
  ListNode(E elemVal){
    element = elemVal;
    prev = nullptr;
    next = nullptr;
  }

  ListNode(E elemVal, ListNode* nextVal){
    element = elemVal;
    next = nextVal;
  }

  /*
  Base destructor 
  */
  ~ListNode(){};
};

#endif