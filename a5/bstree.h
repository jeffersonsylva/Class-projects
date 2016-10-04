//*******************************************************************
// CPSC2620 Spring 2015 Prof: Robert
// Implementation of a binary search tree
// Purpose: To read the words from a file and arrange them in increasing order
// Written partly by: Arie
// Revised and modified by: Jefferson Sylva-Iriogbe
// Date: April 19. 2015
//*******************************************************************

#ifndef __BSTREE_H
#define __BSTREE_H


#include <iostream>
#include <memory>
#include <string>
#include <cmath>

using namespace std;

// tree node structure
template <typename T>
struct BSTNode
{
   T x; // data
   std::shared_ptr<BSTNode> parent, left, right;
};


// binary search tree class
template <typename T>
class BST {
  private:
   std::shared_ptr<BSTNode<T>> root;
   int n; // size

  public:

  BST() : n(0) {};

   // add operation
   // PARAMETERS
   // v is the value to be stored in the tree
   // RETURNS
   // true if v is not already present according to the compare function,
   // false is v exists; in this case, the tree is not modified
   bool add(const T& v)
   {
      std::shared_ptr<BSTNode<T>> p = root;
      std::shared_ptr<BSTNode<T>> node;
	  
	   
      if (root == NULL)
      {
	 root = std::make_shared<BSTNode<T>>();//
	 root-> left = root -> right = root -> parent = NULL;
	 root -> x = v;
	 return true;
      }
      
      while(p)
      {
	 if(compare(p-> x, v) == 0)
	    return false; // checks for duplicates
	      
	 else if (compare(p-> x,v) == -1)
	 {
	    if (p-> right == NULL)
	    {
	       p->right = std::make_shared<BSTNode<T>>();
	       p->right -> left = p->right->right= NULL;
	       p -> right -> parent = p;
	       p-> right -> x = v;
	       n++;
	       return true;
		
	    }

	    else p = p-> right;
	 }
	 else if (compare(p-> x, v) == 1)
	 {
	    p-> left = std::make_shared<BSTNode<T>>();
	    p-> left -> right = p-> left -> left = NULL;
	    p-> left -> parent = p;
	    p-> left -> x = v;
	    n++;
	    return true;
	 }
	   
	 else p= p -> left;

   
      }

   }

   // returns a shared_ptr to a copy of the value stored in the tree
   // that is equal to v 
   // PARAMETERS
   // v the value to look for
   // RETURNS
   // a shared_ptr to a copy of the value stored in the tree
   // that is equal to v; if no such value exists, returns
   // a null share_ptr
   std::shared_ptr<T> findEqual(const T& v) const
   {
      std::shared_ptr<BSTNode<T>> find = root;
      
	 
	  while (find)
	  {	      
	     if (compare(v ,find -> x) == 0)
		return std::make_shared<T> (find->x);
	      
	     else if(compare(v ,find -> x) == -1)
	     {
		find = find-> left;
	     }

	     else if(compare(v,find -> x) == 1)
	     {
		find = find -> right;
	     }
	     
	     //std::shared_ptr<T>(g)= find->x	

	  }
      
	      
      if (find == NULL)
	 return NULL;
	 
   }
 

     
   // RETURNS the number of elements in the tree
   int size() const
   {
      return n;
   }

		
   // sets the node whose value equals v, to v
   // does not change the tree if no node equals v
   void set(const T& v)
   {
      std::shared_ptr<BSTNode<T>> find = root;

      while (find)
      {
	 if (find == NULL)
	    return;

	 else
	 {
	      
	    if (compare(v,find -> x) == 0)
	       find->x = v;
	   
	    else if(compare(v, find -> x) == -1)
	    {
	       find = find-> left;
	  
	    }

	    else if( compare(v , find -> x) == 1)
	    {
	       find = find -> right;
	 
	    }
	 
	 }	
      }
      
      
   }

   void print()
   {
      print_helper(root);
   }

   void print_helper(std::shared_ptr<BSTNode<T>> dummy) // This helper function enables to print the words in the binary search tree without calling any parameters
   {

      if(!dummy)
	 return;
      print_helper(dummy -> left);
      std::cout << " " << dummy -> x << std:: endl;
      print_helper(dummy-> right);

   }

       

   /*dummy = root;
     while(dummy)
     {
     if(dummy->left)
     {
     //  print(dummy-> left);
     std:: cout << " " << dummy -> left;
     dummy = dummy-> left;
     }
     else
     {
     // print(dummy->right);
     std:: cout << " " << dummy-> right;

     dummy=dummy->right;
		 
     }
   */
   //}
   // add any public methods that are needed to fullfill the tasks in
   // the assignment

   // helper functions
  private:
   // you may add any helper functions here.
};


#endif
