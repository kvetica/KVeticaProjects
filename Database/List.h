/*
Kaitlyn Vetica
CPSC 350-03
Header and template file for List class. Defines the methods and private members of 
a list. 
*/


template <typename E>
class List{
public:
  List(){} // default constructor
  virtual ~List() {} // base destructor

  // clear list
  virtual void clear() = 0; // means this has no definition, but must be defined if implemented/inherited

  // insert element at current location
  // @param item: element to be inserted
  virtual void insert(E item) = 0;

  //append element at the end fo the list
  // @param item: element to be appended
  virtual void append(E item) = 0;

  // remove and return current element
  // @return the element that was removed
  virtual E remove() = 0;

  // set the current position to the start of the list
  virtual void moveToStart() = 0;

  // set the current position to the end of the list
  virtual void moveToEnd() = 0;

  // move the current position one step to the left
  virtual void previous() = 0;

  // move the current position one step to the right
  virtual void next() = 0;

  // return the number of elements in the list
  virtual int length() = 0;

  // return the position of the current element
  virtual int currPos() = 0;

  // set the current position
  // @param pos: the posiiton to make current
  virtual void moveToPos(int pos) = 0;

  // return the current element
  virtual E getValue() = 0;

};
