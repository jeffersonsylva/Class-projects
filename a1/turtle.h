#ifndef TURTLE_H
#define TURTLE_H

class turtle
{
  private :
   double x , y ;					
   bool penDown;
   int orientation;

  public:
   turtle();
   turtle(double, double, bool, int);
   void fd(int);
   void bk(int);
   void rt(int);
   void lt(int);
   void pu();
   void pd();
   void home();
   void display();
//helper functions below
   void circle(turtle);
   void triangle(turtle);
   void leaf(turtle);
   void semicircle(turtle);
   void thing(turtle);
   
};

#endif
