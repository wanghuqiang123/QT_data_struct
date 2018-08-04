#include <iostream>
#include <ctime>
#include "sort.h"
#include "staticarray.h"


using namespace std;
using namespace Wanglib;

struct Test:public Object
{
    int id;
    int data1[1000];
    double data2[500];

    bool operator<(const Test& obj)
    {
        return id<obj.id;
    }

    bool operator>=(const Test& obj)
    {
        return id>=obj.id;
    }

    bool operator>(const Test& obj)
    {
        return id>obj.id;
    }

    bool operator<=(const Test& obj)
    {
        return id<=obj.id;
    }

};

class TestProxy:public Object
{
protected:
    Test* m_pTest;
public:

    int id()
    {
        return m_pTest->id;
    }

    int *data1()
    {
        return m_pTest->data1;
    }
    double * data2()
    {
        return m_pTest->data2;
    }

    Test& test()const
    {
        return *m_pTest;
    }
    bool operator<(const TestProxy& obj)
    {
        return test()<obj.test();
    }

    bool operator>=(const TestProxy& obj)
    {
        return  test()>=obj.test();
    }

    bool operator>(const TestProxy& obj)
    {
        return  test()>obj.test();
    }

    bool operator<=(const TestProxy& obj)
    {
        return  test()<=obj.test();
    }

    Test& operator =(Test& test) //这里是提高效率的关键  利用指针进行代理工作，避免了自定义类型中在赋值中的自定义类类型更大的赋值构造开销，而直接利用指针则是可以降低这种开销
    {
        m_pTest = &test;
        return test;
    }
};

Test t[1000];
TestProxy pt[1000];

int main()
{
    clock_t begin = 0;
    clock_t end = 0;
    for(int i = 0;i<1000;i++)
    {
        t[i].id = i;
        pt[i] = t[i];
    }

    begin = clock();

    Sort::Bubble(pt,1000,false);

    end = clock();

    cout<<"Time :"<<(end - begin)<<endl;

    for(int i = 0;i<1000;i++)
    {
        cout<< t[i].id<<"  "<<pt[i].id()<<endl;
    }

    return 0;
}









