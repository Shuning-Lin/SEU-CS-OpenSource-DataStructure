#include <iostream>
using namespace std;

template<typename T>
class node
{
public:
    node(T v):value(v),ptr(nullptr)
    {
        //empty body;
    }
    T value;
    node* ptr;
};

template<typename T>
class linked_list
{
public:
    linked_list():head(nullptr),tail(nullptr)
    {
        //empty body;
    }

    void add_element(T value)
    {
        node<T>* temp = new node<T>(value);
        if (head==nullptr)
            tail=head=temp;
        else
        {
            tail->ptr=temp;
            tail=tail->ptr;
        }
    }

    node<T>* head;
    node<T>* tail;
};

int main()
{
    linked_list<int> a;
    for(int i=0;i<6;i++)
        a.add_element(i);

    node<int>* temp = a.head;
    for(int i=0;i<3;i++)
        temp = temp->ptr;
    a.tail->ptr = temp;

    node<int>* quick_ptr = a.head -> ptr;
    node<int>* slow_ptr = a.head;

    while(quick_ptr->ptr != nullptr and quick_ptr->ptr->ptr != nullptr and quick_ptr != slow_ptr)
    {
        quick_ptr = quick_ptr->ptr->ptr;
        slow_ptr = slow_ptr -> ptr;
    }
    bool flag;
    if(quick_ptr == slow_ptr)
        flag=true;
    else
        flag=false;

    if (flag)
    {
        node<int>* ptr1 = quick_ptr;
        node<int>* ptr2 = quick_ptr->ptr;

        node<int>* check_ptr = a.head;
        while(!(check_ptr->ptr == ptr2 and check_ptr != ptr1))
        {
            while(check_ptr->ptr != ptr2)
                check_ptr = check_ptr->ptr;
            if(check_ptr == ptr1)
            {
                check_ptr = a.head;
                ptr1 = ptr2;
                ptr2 = ptr2 ->ptr;
            }
            else
                break;
        }
        cout<<"The pointer of the start of circle is "<<check_ptr->ptr<<" and the value is "<<check_ptr->ptr->value<<endl;
    }
    else
    {
        cout<<"No circle"<<endl;
        return 0;
    }
}