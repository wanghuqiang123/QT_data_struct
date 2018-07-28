#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;
using namespace Wanglib;



void HanoiTower(int n,char a,char b,char c)   //a ==> src,b==>middle  c==>dest
{
   if(n==1)
   {
       cout<<a<<"-->"<<c<<endl;
   }
   else
   {
       HanoiTower(n-1,a,c,b);
       HanoiTower(1,a,b,c);
       HanoiTower(n-1,b,a,c);
   }
}

int main()
{

    HanoiTower(3,'a','b','c');
    return 0;
}





