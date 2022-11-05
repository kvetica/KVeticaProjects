/*
Kaitlyn Vetica
CPSC 350-03
Header and template file for Stacks class. Declares all necessary functions needed for stack implementation.
Declares constructor, destructor, and all other functions needed for stack.
These methods are defined in LStack and other implementations of Stack class
*/


template <typename E>
class Stack{
public:
  /*
  Default constructor
  */
  Stack() {}

  /*
  Base destructor
  */
  virtual ~Stack() {}

  /*
  clear function
  Reinitializes the stack and deletes its previous contents.
  */
  virtual void clear() = 0;

  /*
  push function
  push an alement onto the top of the Stack
  @param const E& item - element being pushed
  */
  virtual void push(const E& item) = 0;

  /*
  pop function
  Rsemoves and returns the element from the top of the stack
  @return E - the element at the top
  */
  virtual E pop() = 0;

  /*
  topValue function
  Return a copy of the top element
  @return E - The element at the top
  */
  virtual E topValue() = 0;

  /*
  length function
  Returns the number of elements in the stack
  @return int - The number of elements in stack 
  */
  virtual int length() = 0;

};
