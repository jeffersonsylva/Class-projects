// CSPC 2620 Spring 2015 Prof: Robert
// File : slist.h
// modified and written partly by: jefferson sylva-iriogbe
// Date : April 14, 2015
// This code implements three different methods (add, remove and set) using singly linked lists
//***********************************************************************************************

#ifndef __SLIST_H
#define __SLIST_H

#include <memory>
#include <iostream>

// list node structure
template <typename T>
struct Node {
   T x; // data
   std::shared_ptr<Node<T>> next;

   // creating a node with provided data
   Node(const T& v) {
      x=v;
   }
};

template <typename T>
class SList {
  private:
   int n; // number of elements
   std::shared_ptr<Node<T>> head, tail;

  public:
   // default constructor
  SList() : n(0) {}

   // METHODS TO BE IMPLEMENTED

   // PARAMETERS
   // i is the position in the list (0 is the first element)
   //   allowed range: 0 .. n, where n is the size of the list before
   //   addition.
   // v is the value to be inserted at position i (elements at
   // elements at indices i..n-1 are shifted to the right. 
   // throws exception runtime_error if i is out of range
   void add(int i, const T & v)
   {
      if (i<=0 || i> n)
      {
	 throw std::runtime_error("");
	 return;
	 }
      
      /*std::shared_ptr<Node<T>> first = head;
      std::shared_ptr<Node<T>> second = head;
      std::shared_ptr<Node<T>> newNode = make_shared<Node<T>>(v);
      */

       std::shared_ptr<Node<T>> first = head;

      for (int j=1; j <= size(); j++)
      {

	 if(i==0)
      {
	 push(v);
	 return;
      }

	
       if (first-> next == NULL)
	 {
	    std::shared_ptr<Node<T>> second = std::make_shared<Node<T>>(v);
	    first-> next = second;
	    n++;
	    return;
	 }


       if(j==i-1)
       {
	  std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(v);
	  newNode-> next= first->next;
	  first->next = newNode;
	  n++;
	  return;

	  }
       
       
	 first = first-> next;
      }
   }

   // PARAMETERS
   // i is the position in the list (0 is the first element)
   //   allowed range: 0..n-1, where n is the size of the list
   // v is the value to be set for the element at position i
   // throws exception runtime_error if i is out of range	
   void set(int i, const T & v)
   {

      std::shared_ptr<Node<T>> node = head;
      
      for (int j=1; j <= n; j++)
      {
      
      if(i==0)
      {
	 node-> x = v;
	 return;
      }
      
	 if(j==i)
	 {
	    node->x = v;
	    return;
	 }

	 node = node -> next;
      }
   }

   // PARAMETERS
   // i is the position in the list (0 is the first element)
   //   allowed range: 0..n-1, where n is the size of the list
   // RETURN
   // the value of the element at position i
   // throws exception runtime_error if i is out of range
   T get(int i)
   {
      std::shared_ptr<Node<T>> node = head;

      for (int j= 0; j <= n; j++)
      {
	 if(j==0)
	    return node->x;
	 if(j==i)
	 {
	    return node->x;
	 }

	 else node = node->next;
	    		
      }
   }

   // PARAMETERS
   // i is the position in the list (0 is the first element)
   //   allowed range: 0..n-1, where n is the size of the list before
   //   removal 
   // RETURN
   // the value of the element at position i
   // the element at position i is removed (elements at positions
   // i+1..n-1 are shifted to the left)
   // throws exception runtime_error if i is out of range	
   T remove(int i)
   {
      std::shared_ptr<Node<T>> first = head;
      T holder = head->x;

     if (i< 0 || i>n)
      {
	 throw std::runtime_error("");
	 return holder;
      }

     
      for(int j=0; j<= size(); j++)
      {
	 if(i==0)
	 {
	    head= head -> next;
	    return holder;
	   first=first->next;
	 }

	 if(j==i-1)
	 {
	    holder = first->next->x;
	    first->next = first->next->next;
	    return holder;
	    first=first->next;
	    }
	 
      }
   }

   // IMPLEMENTED FUNCTIONS:
   // insert in front
   void push(const T& v) {
      std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(v);  // creates the node
      if (n==0)
      {
	 head = tail = node;
      }
      else
      {
	 node->next = head;
	 head = node;
      }
      n++;
   }

   // returns the number of elements in the list
   int size()
   {
      return n;
   }

   // prints the elements from beginning to the end, each element
   // separated by a space 
   void print()
   {
      for (std::shared_ptr<Node<T>> p = head; p; p = p->next)
	 std::cout << p->x << ' ';
      std::cout << std::endl;
   }
};


#endif
