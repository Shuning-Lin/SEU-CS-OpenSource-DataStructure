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
    for(int i=1;i<=6;i++)
        a.add_element(i);

    node<int>* ptr = a.head;
    cout<<"The following is a simple test:\n";
    while(ptr!=nullptr)
    {
        cout<<ptr->value<<" ";
        ptr = ptr->ptr;
    }

    cout<<"\nPlease input the k(count from the bottom):\n";
    int k;cin>>k;
    ptr=a.head;
    for(int i=0;i<k;i++)
    {
        if(ptr==nullptr)
        {
            cout<<"This number doesn't exist\n";
            return 0;
        }
        ptr=ptr->ptr;
    }

    node<int>* ptr_k=a.head;
    while(ptr!=nullptr)
    {
        ptr = ptr->ptr;
        ptr_k=ptr_k->ptr;
    }
    cout<<"The number which is k_th counts from the bottom is:\n";
    cout<<ptr_k->value;
    return 0;
}
