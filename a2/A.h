#include<iostream>

class A {

  private:
   int v;


  public:
   //constructor
  A(int val=0) : v(val) {

      std::cout << "A(" << v<< ")" << std :: endl;
   };

   //destructor
   ~A() {
      std:: cout << "~A(): value " << v << std :: endl;
      
   }

   //setter

   void set(int val)
   {
      v=val;
   }

   // getter
   int get() {
      return v;

   }


};
