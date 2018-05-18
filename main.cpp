#include <iostream>
#include "LinkQueue.h"
#include "staticqueue.h"

using namespace std;
using namespace Wanglib;

class test:public Object
{
public:
    test()
    {
        cout<<"test()"<<endl;
    }
    ~test()
    {
        cout<<"~test()"<<endl;
    }
};

int main()
{
    LinkQueue<test>queue;
    StaticQueue<test,5>q;
   /* for(int i =0;i<5;i++)
    {
        queue.add(i);
    }
    while (queue.length()>0)
    {
        cout<<queue.front()<<endl;

        queue.remove();
    }*/
    return 0;
}


