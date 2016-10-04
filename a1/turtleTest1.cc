#include"turtle.h"

int main()
{
   turtle r;
   for (int i=0; i< 37; i++)
   {    
      r.bk(50);
      r.home();
      r.lt(i*10);
   }

   turtle b (200, 160 , true , 90);

   for (int i=0; i < 10; i++)
   {
      b.fd(10);
      b.pu();
      b.fd(10);
      b.pd();
   }

   r.display();
   return 0;
}



