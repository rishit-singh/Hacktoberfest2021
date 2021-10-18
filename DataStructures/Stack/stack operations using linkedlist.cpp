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
int main()
{
  stack s;
  int choice;
  cout<<"------------------------STACK OPERATION USING LIST-------------------------"<<endl;
  cout<<"1.PUSH\n2.POP\n3.TOP ELEMENT\n4.SIZE OF THE STACK\n5.FIND ELEMENT AT INDEX\n6.DISPLAY\n0.EXIT\n";
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
        if(s.push(value))
          cout<<"INSERTING ELEMENT:"<<value<<endl;
        else
          cout<<"INSERTION FAILED"<<endl;
        break;
      }
      case 2:
        cout<<"REMOVING ELEMENT:"<<s.pop()<<endl;
        break;
      case 3:
        cout<<"STACK TOPMOST ELEMENT:"<<s.stackTop()<<endl;
        break;
      case 4:
        cout<<"NO OF ELEMENTS IN A STACK:"<<s.size()<<endl;
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
        cout<<"ELEMENTS STORED IN A STACK:";
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
