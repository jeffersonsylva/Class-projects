//**********************************************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : slist.h
// modified and written partly by: jefferson sylva-iriogbe
// Date : April 14, 2015
// This code implements three different methods (add, remove and set) using singly linked lists
//***********************************************************************************************

#include"slist.h"
#include<fstream>
#include<iostream>
#include<string>


using namespace std;

int main()
{
   SList <string> slist;
   
   string str;
   string str2;
   int i, value;

   ifstream fin;
   cin>>str2;
   fin.open(str2);
   
  if(fin.is_open()) // checks if the file is open
  {

     try{
      
      while(!fin.eof())
      {
	 fin >> str;
	    
	 if (str == "add")
	    {
	       fin >> value >> str;
	       slist.add(value,str);
	    }

	 
	 else  if (str =="set" )
	    {
	       fin >> value >> str;
	       slist.set(value, str);
	    }
	 
	 else if (str == "remove")
	 {
	       fin >> i;
	       slist.remove(i);
	    }
	 
	 else if ( str == "quit" )
	    {
	       break;
	    }
	 else cout << "Syntax error(s) were encountered." << endl;
      }
     }
     catch(std::runtime_error)
     {
	slist.print();
	cout << "List error(s) were encountered." << endl;
     }
  }
      
      slist.print();
  
 
   return 0;
   
}
