/*
Kaitlyn Vetica
CPSC 350-03
Header and template file for LStack class. Defines the methods and private members of 
a list based stack. Uses ListNodes as the pointers that are contained in the list stack. 
*/

#include "Stack.h"
#include "ListNode.h"

template <typename E>
class LStack : public Stack<E>{
private:
  ListNode<E>* top; // pointer to first element
  int size; // number of elements
public:
  LStack(int sz);
  ~LStack();
  void clear();
  void push(const E& item);
  E pop();
  E topValue();
  int length();
};

// constructor
template <typename E>
LStack<E>::LStack(int sz){
  top = nullptr;
  size = 0;
}

// destructor
template <typename E>
LStack<E>::~LStack(){
  clear();
}

/*
clear
Clears the list stack so it is empty
*/
template <typename E> 
void LStack<E>::clear(){
  while(top!=nullptr){
    ListNode<E>* temp = top;
    top = top->next;
    delete temp;
  }
  size = 0;
}

/*
push
Adds the given item to the top of the stack 
@param const E& item - Item to be added onto stack 
*/
template <typename E>
void LStack<E>::push(const E& item){
  top = new ListNode<E>(item,top);
  size++;
}

/*
pop
Removes top item from the stack 
@return E - Returns item that is removed from stack.
*/
template <typename E>
E LStack<E>::pop(){
  if(top==nullptr){
    E value = E();
    return value;
  }
  E item = top->element;
  ListNode<E>* temp = top->next;
  delete top;
  top = temp;
  size--;
  return item;
}

/*
topValue 
Returns the top value of the stack without removing it 
@return E - Top value of stack 
*/
template <typename E>
E LStack<E>::topValue(){
  if(size==0){
    E value = E();
    return value;
  }
  return top->element;
}

/*
length
Returns the length/size of the stack 
@return int - Size of the stack 
*/
template <typename E>
int LStack<E>::length(){
  return size;
}
