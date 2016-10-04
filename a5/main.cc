//*******************************************************************
// CPSC2620 Spring 2015 Prof: Robert
// Implementation of a binary search tree
// Purpose: To read the words from a file and arrange them in increasing order
// Written partly by: Arie
// Revised and modified by: Jefferson Sylva-Iriogbe
// Date: April 19. 2015
//*******************************************************************

#include "bstree.h"
#include<fstream>

using namespace std;
// BST as a dictionary: name=the key, value=the value stored for the key
struct Data {
   std::string name;
   int value;

   Data(std::string n, int v=1) {
      name = n;  value = v;
   }

   // members value initialized (default constructor)
   Data() : value(1) { };
};


// can be useful for debugging purposes
std::ostream & operator << (std::ostream& str, Data d) {
   str << d.name << "(" << d.value << ") ";
   return str;
}

int compare(Data a, Data b) {
   if (a.name == b.name)
      return 0;
   else if (a.name < b.name)
      return -1;

   else
      return 1;
}


#include <string>
int main()
{
   BST<Data> b;   

   string filename;
 
   while(cin >> filename)
   {
      Data d(filename);

      b.add(filename);  
   
      std:: shared_ptr<Data> pdata = b.findEqual(d);
      if (pdata)
      {
	 pdata-> value++;
	 //b.set(*pdata);
      }  

      b.print();
      }
   
   return 0;
}
