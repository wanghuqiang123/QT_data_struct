#include <iostream>
#include "circledualist.h"

using namespace std;
using namespace Wanglib;


int main()
{
    DuaCirclelist<int>d;

    for(int i = 0;i<5;i++)
    {
        d.insert(0,i);
        d.insert(0,5);
    }



   cout<<"begin"<<endl;

   d.move(d.length()-1);

   while(d.find(5) != -1)
   {
       if(d.current() == 5)
       {
           cout<<d.current()<<endl;
           d.remove(d.find(d.current()));
       }
       else
       {
           d.pre();
       }
   }

    cout<<"end"<<endl;
    for(d.move(0);!d.end();d.next())
    {
        cout<<d.get(i)<<endl;
    }
    return 0;
}


