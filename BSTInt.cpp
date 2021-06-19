//Name:Sergelenbayar Tsogtbaatar
//Date:January 21, 2017
//Overview: contains headers functions for int-based BST class
//Assignment Number: 1


#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
   if(root){
     deleteAll(root);
   }
   
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  BSTNodeInt* curr = root;

  //if no root then create one
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }   
  //infinite loop
  while(1){
     //handles left side
       if(item < (curr->data)){
          if(curr->left == 0){
             BSTNodeInt* newNode = new BSTNodeInt(item);
             curr->left = newNode;
             newNode->parent = curr;
             ++isize;
             return true;
             }
             curr = curr->left;
        }
        //handles right side
        else if((curr->data)<item){
           if(curr->right == 0){
              BSTNodeInt* newNode = new BSTNodeInt(item);
              curr->right = newNode;
              newNode->parent = curr;
              ++isize;
              return true;
             }
             curr = curr->right;
        }
        //if equal
        else{
           return false;
        }
    }

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
   //empty check
   if(empty()){
      return false;
   }
  BSTNodeInt* curr = root;
  //traversal
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if(item < curr->data) {
      curr = curr->left;
    }
    else{
       return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
 */
int BSTInt::height() const
{
  // TODO
  int max = 0;
  BSTNodeInt* temp = root;
  if(isize == 0){
     return -1;
  }
  max = heightHelp(temp);
  return (max-1);
}

int BSTInt::heightHelp(BSTNodeInt* x) const
{
   int left = 0;
   int right = 0;
   if(x->left){
      left = heightHelp(x->left);
   }
   if(x->right){
      right = heightHelp(x->right);
   }
   
   
   if(left < right){
      return right + 1;
   }
   else{
      return left +1;
   }


}
/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  if(isize == 0){
    return true;
  }
  else{
     return false; 
     }
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  if(n->left){
    deleteAll(n->left);
  }
  if(n->right){
     deleteAll(n->right);
  }
  delete(n);
  }
