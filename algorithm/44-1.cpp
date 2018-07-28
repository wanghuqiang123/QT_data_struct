#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;
using namespace Wanglib;

struct  Node
{
     int value;
     Node* next;
};

Node* create_list(int v,int len)
{
    Node* ret = NULL;
    Node* slider = NULL;

    for(int i=0;i<len;i++)
    {
        Node* n = new Node();

        n->value = v++;
        n->next = NULL;

        if(slider == NULL)
        {
            slider = n;
            ret = n;
        }
        else
        {
            slider->next = n;
            slider = n;
        }
    }
    return ret;
}

void destory_list(Node* list)
{
    while(list)
    {
        Node* del = list;
        list = list->next;
        delete del;
    }
}

void print_list(Node* list)
{
    while(list)
    {
        cout<<list->value<<"->";
        list = list->next;
    }
    cout<<"NULL"<<endl;
}

Node* reverse(Node* list)
{
    if((list == NULL) || (list->next == NULL) )
    {
        return list;
    }
    else
    {
        Node* guard = list->next;
        Node* ret = reverse(list->next);

        guard->next = list;
        list->next = NULL;

        return ret;
    }
}

Node* merge(Node* list1,Node* list2)
{
    if(list1 == NULL)
    {
        return list2;
    }
    else if(list2 == NULL)
    {
        return list1;
    }
    else if(list1->value<list2->value)
    {
        return (list1->next = merge(list1->next,list2),list1);
    }
    else
    {
        return (list2->next = merge(list2->next,list1),list2);
    }
}

int main()
{
    Node* list1 = create_list(1,5);
    Node* list2 = create_list(2,6);

    print_list(list1);
    print_list(list2);

    Node* list = merge(list1,list2);

    print_list(list);

    destory_list(list);

    return 0;
}





