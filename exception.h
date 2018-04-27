#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "object.h"

namespace Wanglib
{

#define THROW_EXCEPTION(e,m) (throw e(m,__FILE__,__LINE__))
class Exception:public Object
    {
    protected:
        char* m_message;
        char* m_location;

        void init(const char* message,const char* file,int line);
    public:
        Exception(const char* me);
        Exception(const char* file,int line);
        Exception(const char* message,const char* file,int line);

        Exception(const Exception& e);
        Exception& operator=(const Exception& e);

        virtual const char* message()const;        //产生错误的信息
        virtual const char* location()const;       //定位错误的位置，查看相应的行号；

        virtual ~Exception();
    };

    class ArithmeticException:public Exception
    {
    public:
        ArithmeticException():Exception(0){}
        ArithmeticException(const char* message):Exception(message){}
        ArithmeticException(const char* file,int line):Exception(file,line){}
        ArithmeticException(const char* message,const char* file,int line):Exception(message,file,line){}

        ArithmeticException(const ArithmeticException& e):Exception(e){}
        ArithmeticException& operator =(const ArithmeticException& e)   //拷贝构造函数的话必须参数与返回值类型都是引用
        {
            Exception::operator =( e );

            return *this;
        }
    };

    class NoEnoughMemoryException:public Exception
    {
    public:
        NoEnoughMemoryException():Exception(0){}
        NoEnoughMemoryException(const char* message):Exception(message){}
        NoEnoughMemoryException(const char* file,int line):Exception(file,line){}
        NoEnoughMemoryException(const char* message,const char* file,int line):Exception(message,file,line){ }
        NoEnoughMemoryException(const NoEnoughMemoryException& e):Exception(e){}

        NoEnoughMemoryException& operator =(const NoEnoughMemoryException& e)
        {
            Exception::operator =(e);

            return *this;
        }
    };

    class InvalidParameterException:public Exception
    {
    public:
        InvalidParameterException():Exception(0){}
        InvalidParameterException(const char* message):Exception(message){}
        InvalidParameterException(const char* file,int line):Exception(file,line){}
        InvalidParameterException(const char* message,const char* file,int line):Exception(message,file,line){ }
        InvalidParameterException(const InvalidParameterException& e):Exception(e){}

        InvalidParameterException& operator =(const InvalidParameterException& e)
        {
            Exception::operator =(e);

            return *this;
        }
    };

    class InvalidOperationException:public Exception
    {
    public:
       InvalidOperationException():Exception(0){}
       InvalidOperationException(const char* message):Exception(message){}
       InvalidOperationException(const char* file,int line):Exception(file,line){}
       InvalidOperationException(const char* message,const char* file,int line):Exception(message,file,line){ }
       InvalidOperationException(const InvalidOperationException& e):Exception(e){}

        InvalidOperationException& operator =(const InvalidOperationException& e)
        {
            Exception::operator =(e);

            return *this;
        }
    };

    class IndexOutOfBoundsException:public Exception
    {
    public:
       IndexOutOfBoundsException():Exception(0){}
       IndexOutOfBoundsException(const char* message):Exception(message){}
       IndexOutOfBoundsException(const char* file,int line):Exception(file,line){}
       IndexOutOfBoundsException(const char* message,const char* file,int line):Exception(message,file,line){ }
       IndexOutOfBoundsException(const IndexOutOfBoundsException& e):Exception(e){}

        IndexOutOfBoundsException& operator =(const IndexOutOfBoundsException& e)
        {
            Exception::operator =(e);

            return *this;
        }
    };
}

#endif // EXCEPTION_H

