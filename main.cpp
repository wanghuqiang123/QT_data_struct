#include <iostream>
#include "Exception.h"

using namespace std;
using namespace Wanglib;


int main()
{

    try
    {
        THROW_EXCEPTION(ArithmeticException,"test");
    }
    catch(const Exception& e)    //赋值兼容性原则，父类可以给子类 ，非const可以给const
    {
        cout<<"catch(const Exception& e)"<<endl;
        cout<<e.message()<<endl;
        cout<<e.location()<<endl;
    }

    return 0;
}

