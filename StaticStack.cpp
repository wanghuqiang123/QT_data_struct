#include <iostream>
#include "linkstack.h"
#include "linkqueue.h"

using namespace std;
using namespace Wanglib;

template <typename T>
class StackToQueue:public  Queue<T>
{
protected:
    LinkStack<T>m_stack_in;
    LinkStack<T>m_stack_out;
    void move()
    {
        if(m_stack_out.size() == 0)
        {
            while(m_stack_in.size()>0)
            {
                m_stack_out.push(m_stack_in.top());
                m_stack_in.pop();
            }
        }
    }
public:
     void add(const T& e)
     {
        m_stack_in.push(e);
     }
     void remove()
     {
        move();
        if(m_stack_out.size()>0)
        {
          m_stack_out.pop();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in current queue");
        }
     }
     T front()
     {
         move();
         if(m_stack_out.size()>0)
         {
           return m_stack_out.top();
         }
         else
         {
             THROW_EXCEPTION(InvalidOperationException,"No element in current queue");
         }
     }
     void clear()
     {
         m_stack_in.clear();
         m_stack_out.clear();
     }
     int length() const
     {
         return m_stack_in.size()+m_stack_out.size();
     }
};

int main()
{
    StackToQueue<int>sq;
    for(int i = 0;i<10;i++)
    {
        sq.add(i);
    }

    while (sq.length()>0)
    {
        cout<<sq.front()<<endl;
        sq.remove();
    }
    return 0;
}


