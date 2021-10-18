#include<iostream>
using namespace std;
class stack
{
   int *arr;
   int top;
   int capacity;
  public:
    stack(int s)
    {
      arr=new int[s];
      capacity=s;
      top=-1;
    }
    ~stack()
    {
      delete [] arr;
    }
    void push(int);
    void pop();
    bool isEmpty();
    bool isFull();
    int stackTop();
    int size();
    int find(int);
    void display();
};
bool stack::isFull()
{
  return top==capacity-1;
}
bool stack::isEmpty()
{
  return top==-1;
}
void stack::push(int x) {
  if(isFull())
    cout<<"STACK OVERFLOW"<<endl;
  else
  {
    cout<<"INSERTING ELEMENT:"<<x<<endl;
    arr[++top]=x;
  }
}
int stack::stackTop()
{
  if(isEmpty())
  {
    cout<<"STACK IS EMPTY"<<endl;
    return -1;
  }
  else
    return arr[top];
}
void stack::pop()
{
  if(isEmpty())
    cout<<"STACK UNDERFLOW"<<endl;
  else
  {
    cout<<"REMOVING ELEMENT:"<<stackTop()<<endl;
    top--;
  }
}
/* top=3    index=top-position+1
     position   index
        1         3
        2         2
        3         1
        4         0
*/
int stack::find(int pos)
{
  if(isEmpty())
    cout<<"STACK IS EMPTY"<<endl;
  int x=-1;
  if(top-pos+1<0 || top-pos+1>top)
    cout<<"INVALID POSITION"<<endl;
  else
    x=arr[top-pos+1];
  return x;
}
int stack::size()
{
  return top+1;
}
void stack::display()
{
  if(isEmpty())
    cout<<"STACK IS EMPTY"<<endl;
  else
  {
    for(int i=0;i<=top;i++)
      cout<<arr[i]<<" ";
    cout<<endl;
  }
}
int main()
{
  int choice,n;
  cout<<"------------------------STACK OPERATION USING ARRAY-------------------------"<<endl;
  cout<<"1.PUSH\n2.POP\n3.TOP ELEMENT\n4.SIZE OF THE STACK\n5.FIND ELEMENT AT INDEX\n6.DISPLAY\n0.EXIT\n";
  cout<<"----------------------------------------------------------------------------"<<endl;
  cout<<"ENTER THE NO OF THE ELEMENTS:";
  cin>>n;
  stack s(n);
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
        s.push(value);
        break;
      }
      case 2:
        s.pop();
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
