//*******************************************************************
// CPSC2620 Spring 2015 Prof: Robert
// Definition File for Turtle class
// Purpose: To create the Turtle Class Definition
// Written by: Arie
// Revised by: RB
// Date: Feb 6. 2015
//*******************************************************************
#ifndef TURTLE_H
#define TURTLE_H

class Turtle
{
  public:
   Turtle(); // default constructor
   Turtle(int, int);
   void pu(); // set pen up
   void pd(); // set pen down
   void fd(double); // move forward
   void bk(double); // move back
   void rt(int); // turn (degrees)
   void lt(int); // turn (degrees)
   void home();
   void goTo(double, double);
   void setAngle(int);
   double xPos() const; // get x's position
   double yPos() const; // get y's position
   double angleIs() const;
   
   void display() const;
   
  private:
   double x,y; // x,y coordinates
   bool penDown; // is this turtle's pen up or down?
   int angle; // what is the angle of orientation of this turtle
};
#endif

