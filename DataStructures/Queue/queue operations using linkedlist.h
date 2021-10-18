#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class queue
{
    node * front;
    node * rear;
    public:
    int capacity;
    queue()
    {
        capacity=0;
        front=NULL;
        rear=NULL;
    }
    void enqueue(int);
    void dequeue();
    int find(int);
    void display();
    bool isEmpty();
    int queueFront();
    int queueSize();
};
bool queue::isEmpty()
{
    return rear==NULL && front==NULL;
}
void queue::enqueue(int x)
{
    node *t=new node;
    if(t==NULL)//heap is full
        cout<<"QUEUE OVERFLOW\n";
    else
    {
        cout<<"INSERTING ELEMENT:"<<x<<endl;
        capacity++;
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}
int queue::queueFront()
{
    if(isEmpty())
    {
        cout<<"QUEUE IS EMPTY\n";
        return -1;
    }
    else
        return front->data;
}
void queue::dequeue()
{
    if(isEmpty())
        cout<<"QUEUE UNDERFLOW\n";
    else
    {
        int x;
        capacity--;
        if(front==rear)
        {
            delete(front);
            front=rear=NULL;
        }
        else
        {
            x=front->data;
            node *t=front;
            front=front->next;
            delete t;
        }
        cout<<"REMOVING ELEMENT:"<<x<<endl;
    }
}
int queue::find(int pos)
{
    if(!(0<pos && pos<=capacity))
    {
        cout<<"INVALID INDEX"<<endl;
        return -1;
    }
    else
    {
        node *p=front;
        for(int i=1;i<pos;i++)
        {
            p=p->next;
        }
        int x=p->data;
        return x ;
    }
}
int queue::queueSize()
{
    return capacity;
}
void queue::display()
{
    if(isEmpty())
        cout<<"Queue is empty"<<endl;
    else
    {
        node *p=front;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
