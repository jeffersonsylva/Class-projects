
#ifndef ISTACK_H
#define ISTACK_H

class IStack {

   vector<int> *stof;

  public:
   IStack();
   ~IStack();
   int size();
   void pop();
   void top();
   void push(int);


};



#endif 
