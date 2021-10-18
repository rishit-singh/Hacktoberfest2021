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
int main()
{
  int choice,n;
  cout<<"------------------------QUEUE OPERATION USING LIST-------------------------"<<endl;
  cout<<"1.ENQUEUE\n2.DEQUEUE\n3.TOP ELEMENT\n4.SIZE OF THE QUEUE\n5.FIND ELEMENT AT INDEX\n6.DISPLAY\n0.EXIT\n";
  queue s;
  do{
    cout<<"\n------------------------------------------------------------------------"<<endl;
    cout<<"ENTER YOUR OPTION:";
    cin>>choice;
    switch (choice) {
      case 0:
        cout<<"EXITING.....";
        break;
      case 1:
      {
        int value;
        cout<<"ENTER THE ELEMENT:";
        cin>>value;
        s.enqueue(value);
        break;
      }
      case 2:
        s.dequeue();
        break;
      case 3:
        cout<<"QUEUE FRONT ELEMENT:"<<s.queueFront()<<endl;
        break;
      case 4:
        cout<<"NO OF ELEMENTS IN A QUEUE:"<<s.queueSize()<<endl;
        break;
      case 5:
      {
        int pos;
        cout<<"ENTER POSITION:";
        cin>>pos;
        cout<<"ELEMENT AT GIVEN POSITION "<<pos<<":"<<s.find(pos)<<endl;
        break;
      }
      case 6:
      {
        cout<<"ELEMENTS STORED IN A QUEUE:";
        s.display();
        break;
      }
      default:
      cout<<"INVALID OPTION, TRY AGAIN!"<<endl;
    }
  }
    while(choice!=0);
    return 0;
  }
