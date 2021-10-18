#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class stack
{
    node * top;
    public:
    int capacity;
    stack()
    {
        capacity=0;
        top=NULL;
    }
    ~stack()
    {
        delete top;
    }
    bool push(int);
    int pop();
    int find(int);
    void display();
    bool isEmpty();
    int stackTop();
    int size();
};
bool stack::isEmpty()
{
    return top==NULL;
}
bool stack::push(int x)
{
    node *t=new node;
    if(t==NULL)//heap is full
    {
        cout<<"STACK OVERFLOW\n";
        return false;
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
        capacity++;
        return true;
    }
}
int stack::stackTop()
{
    if(isEmpty())
    {
        cout<<"STACK IS EMPTY\n";
        return -1;
    }
    else
        return top->data;
}
int stack::pop()
{
    if(isEmpty())
    {
        cout<<"STACK UNDERFLOW\n";
        return -1;
    }
    else
    {
        int x=top->data;
        node *t=top;
        top=top->next;
        delete(t);
        capacity--;
        return x;
    }
}
int stack::find(int pos)
{
    if(!(0<pos && pos<=capacity))
    {
        cout<<"INVALID INDEX"<<endl;
        return -1;
    }
    else
    {
        node *p=top;
        for(int i=1;i<pos;i++)
        {
            p=p->next;
        }
        int x=p->data;
        return x ;
    }
}
int stack::size()
{
    return capacity;
}
void stack::display()
{
    if(isEmpty())
        cout<<"STACK IS EMPTY"<<endl;
    else
    {
        node *p=top;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
