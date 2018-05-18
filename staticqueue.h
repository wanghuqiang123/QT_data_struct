#ifndef STATICQUEUE_H
#define STATICQUEUE_H
#include "queue.h"
#include "Exception.h"

namespace Wanglib {

template<typename T,int N>
class StaticQueue:public Queue<T>
{
protected:
    T m_space[N];
    int m_front;
    int m_rear;
    int m_length;
public:
    StaticQueue()
    {
        m_front = 0;
        m_rear = 0;
        m_length = 0;
    }

    int capacity()const
    {
        return N;
    }

    void add(const T& e)
    {
        if(m_length<N)
        {
            m_space[m_rear] = e;
            m_rear = (m_rear+1)%N;
            m_length++;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No space in currnt queue..");
        }
    }
    void remove()
    {
        if(m_length>0)
        {
            m_front = (m_front+1)%N;
            m_length--;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in currnt queue..");
        }
    }

    T front()
    {
        if(m_length>0)
        {
            return m_space[m_front];
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in currnt queue..");
        }
    }

    void clear()
    {
        m_front = 0;
        m_rear = 0;
        m_length = 0;
    }
    int length()const
    {
        return m_length;
    }


};

}

#endif // STATICQUEUE_H
