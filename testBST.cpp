//Name:Sergelenbayar Tsogtbaatar
//Date:January 21, 2017
//Overview: contains tests for PA1.
//Assignment Number: 1


#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and Sergelenbayar Tsogbaatar
 * TODO: Add more tests
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    vector<int> v1;
    vector<int> v2;

    v1.push_back(3);

    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(1);
    v2.push_back(100);
    v2.push_back(101);



    /* Create an instance of BST holding int */
    BSTInt b;
    BSTInt b1;
    BSTInt b2;
    // Could use: for(auto item : v) { instead of the line below

    //populate v1
    for(int item : v1) {
        bool pr = b1.insert(item);
  
        if(! pr ) {
 
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }  
    //populate v2
    for(int item : v2) {
        bool pr = b2.insert(item);
  
        if(! pr ) {
 
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }  

    /* Test size. */
    //empty 
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    cout << "Size is: " << b1.size() << endl;
    if(b1.size() != v1.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    cout << "Size is: " << b2.size() << endl;
    if(b2.size() != v2.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    //empty
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }
    //one
    for(int item : v1) {
        if(!b1.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }
    //five
    for(int item : v2) {
        if(!b2.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /*tests to see if empty with empty() */

    if(b.empty() !=true){
       cout << "Incorrect return value for empty set" << endl;
       return -1;
    }

    if(b1.empty() !=false){
       cout << "empty fails for set of one" << endl;
       return -1;
    }
    if(b2.empty() !=false){
       cout << "empty fails for set of five" << endl;
       return -1;
    }


    /* testing height. */
    if(b.height() != -1){
       cout << "incorrect height for empty set" << endl;
       return -1;
    }
    if(b1.height() != 0){
       cout << "incorrect height for set of one" << endl;
       return -1;
    }
    if(b2.height() != 3){
       cout << "incorrect height for set of five" << endl;
       return -1;
    }

    

    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    BST<int> btemp1;
    BST<int> btemp2;
    vector<int> vec;
    vector<int> vec1;
    vector<int> vec2;

    vec1.push_back(10);

    vec2.push_back(11);
    vec2.push_back(3);
    vec2.push_back(2);
    vec2.push_back(14);
    vec2.push_back(-33);


    //populate vec1
    for (int item : vec1) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp1.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }
    //populate vec2
    for (int item : vec2) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp2.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: vec) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }

    for (int item: vec1) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp1.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }

    for (int item: vec2) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp2.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }





    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(vec2.begin(),vec2.end());

    cout << "traversal using iterator..." << endl;
    auto vit = vec2.begin();
    auto ven = vec2.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp2.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp2.begin();

    for(; vit != ven; ++vit) {
       cout << "first: " << *it << "scond: " << *vit << endl;
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
        cout << "lol" << endl;
    }

    cout << "success!" << endl;

    

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

    // checking empty method
    if(btemp.empty() == false){
       cout << "incorrect return bool, btemp should be emmpty" << endl;
       return -1;
    }
    if(btemp1.empty() == true){
       cout << "incorrect return bool, btemp1 has 1 element" << endl;
       return -1;
    }
    if(btemp2.empty() == true){
       cout << "incorrect return bool, btemp2 is not empty" << endl;
       return -1;
    }

    // testing size function
    
    if(vec.size() != btemp.size()){
       cout << "incorrect, vec and btemp should be both empty" << endl;
       return -1;
    }
    if(vec1.size() != btemp1.size()){
       cout << "incorrect bc vec1 and btemp1 should be same size" << endl;
       return -1;
    }
    if(vec2.size() != btemp2.size()){
       cout << "incorrect bc vec2 and btemp2 should be same size" << endl;
       return -1;
    }

    //tesing height function
    if(btemp.height() != -1){
       cout << "incorrect bc btemp height should be -1" << endl;
       return -1;
    }
    if(btemp1.height() != 0){
       cout << "incorrect bc btemp1 height should be 0" << endl;
       return -1;
    }
    if(btemp2.height() != 2){
       cout << "incorrect bc btemp2 height should be 2" << endl;
       return -1;
    }

    cout << "All tests passed!" << endl;
    return 0;


    }
