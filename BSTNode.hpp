//Name:Sergelenbayar Tsogtbaatar
//Date:January 21, 2017
//Overview: contains headers and functions for BSTNode class.
//Assignment Number: 1

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

/** Starter code for PA1, CSE 100 2016
 * Authors: Christine Alvarado, based on code by Paul Kube 
 * Author: Sergelenbayar Tsogtbaatar
 * */

template<typename Data>
class BSTNode {

public:
  Data const data;
  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  // the const Data in this node.

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d);


  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor(); 

}; 


// Function definitions
// For a templated class it's easiest to just put them in the same file as the class declaration

template <typename Data>
BSTNode<Data>::BSTNode(const Data & d) : data(d), left(0), right(0), parent(0) {}

/* Return a pointer to the BSTNode that contains the item that is sequentially next 
 * in the tree */
template <typename Data>
BSTNode<Data>* BSTNode<Data>::successor()
{
   BSTNode<Data>* curr = right;
   if(curr){
      //check the right child
      while(curr->left){
         curr = curr->left;
      }
      return curr;
   }
   //if there is no right child then traverse
   else{
      curr = this;
      BSTNode* prev = this;
      while(curr->left != prev){
         if(!(curr->parent)){
            return 0;
         }
         prev = curr;
         curr = curr->parent;
      }
      return curr;
   }

  return 0;
}

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
