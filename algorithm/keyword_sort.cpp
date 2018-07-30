#include <iostream>
#include <cstdlib>
#include <cstring>
#include "linklist.h"
#include "object.h"
using namespace std;
using namespace Wanglib;

struct Test : public Object
{
    int key1;
    int key2;

    Test(int k1,int k2)
    {
        key1 = k1;
        key2 = k2;
    }

    bool operator ==(const Test& t)
    {
        return (key1 == t.key1) && (key2 == t.key2);
    }

    bool operator !=(const Test& t)
    {
        return !(*this == t);
    }

    bool operator <(const Test& t)
    {
        return (key1<t.key1)||((key1 == t.key1)&&(key2 < t.key2));
    }

    bool operator >=(const Test& t)
    {
        return !(*this < t);
    }

    bool operator>(const Test& t)
    {
        return (key1>t.key1)||((key1==t.key1)&&(key2>t.key2));
    }

    bool operator<=(const Test& t)
    {
        return !(*this > t);
    }

};
int main()
{
    Test t1(3,4);
    Test t2(3,5);

    cout<<(t1<t2)<<endl;
    return 0;
}









