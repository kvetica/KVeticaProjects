/*
Kaitlyn Vetica
CPSC 350-03
Header and template file for TreeNode class. Defines the methods and private members of 
a TreeNode object. TreeNode and its pointers are used in BST class. 
*/

#ifndef TreeNode_h
#define TreeNode_h

template <typename E>
class TreeNode{
public:
  E value; // data value
  int key; // key for the tree
  TreeNode* left; // left child pointer
  TreeNode* right; // right child pointer

  TreeNode();
  TreeNode(int k, E v);
  ~TreeNode();
  void setKey(int k);
  void setValue(E v);
  E getValue();
  int getKey();
};

/*
Default constructor
*/
template <typename E>
TreeNode<E>::TreeNode()
{
  key = 0;
  value = E();
  left = nullptr;
  right = nullptr;
}

/*
Overloaded constructor. Sets values for key and value based on parameters
*/
template <typename E>
TreeNode<E>::TreeNode(int k, E v)
{
  key = k;
  value = v;
  left = nullptr;
  right = nullptr;
}

/*
Destructor
*/
template <typename E>
TreeNode<E>::~TreeNode() {}

/*
setKey
Sets the key of treenode of type int
@param int k - Key value 
*/
template <typename E>
void TreeNode<E>::setKey(int k){
  key = k;
}

/*
setValue
Sets the value of treenode of type E
@param E v - Value
*/
template <typename E>
void TreeNode<E>::setValue(E v){
  value = v;
}

/*
getValue
Returns value of treenode 
@return E - Value
*/
template <typename E>
E TreeNode<E>::getValue(){
  return value;
}

/*
getKey
Returns key of treenode
@return int - Key
*/
template <typename E>
int TreeNode<E>::getKey(){
  return key;
}

#endif
