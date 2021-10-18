#include<iostream>
using namespace std;
class queue
{
   int *arr;
   int front;
   int qsize;
   int rear;
   int capacity;
  public:
    queue(int s)
    {
      arr=new int[s];
      this->qsize=s;
      capacity=0;
      front=rear=-1;
    }
    ~queue()
    {
      delete [] arr;
    }
    void enqueue(int);
    void dequeue();
    bool isEmpty();
    bool isFull();
    int find(int);
    int queueFront();
    int size();
    void display();
};
bool queue::isFull()
{
  return rear==qsize-1;
}
bool queue::isEmpty()
{
  return rear==front==-1;
}
void queue::enqueue(int x) {
  if(isFull())
    cout<<"QUEUE OVERFLOW"<<endl;
  else
  {
    cout<<"INSERTING ELEMENT:"<<x<<endl;
    arr[++rear]=x;
    capacity++;
  }
}
int queue::queueFront()
{
  if(isEmpty())
  {
    cout<<"QUEUE IS EMPTY"<<endl;
    return -1;
  }
  else
    return arr[front+1];
}
void queue::dequeue()
{
  if(isEmpty())
    cout<<"QUEUE UNDERFLOW"<<endl;
  else
  {
    capacity--;
    cout<<"REMOVING ELEMENT:"<<queueFront()<<endl;
    if(front==rear)
      front=rear=-1;
    else
     front++;
  }
}
/* capacity=3  rear=4  index=rear-capacity+position
     position   index    _________________________________
        1         2     |  -  |   -  |  1   |  2   |  3   |
        2         3     |_____|______|______|______|______|
        3         4        0    1      2      3      4
*/
int queue::find(int pos)
{
  if(isEmpty())
    cout<<"QUEUE IS EMPTY"<<endl;
  int x=-1;
  if(rear-capacity+pos <= front || rear-capacity+pos>rear)
    cout<<"INVALID POSITION"<<endl;
  else
    x=arr[rear-capacity+pos];
  return x;
}
int queue::size()
{
  return capacity;
}
void queue::display()
{
  if(isEmpty())
    cout<<"QUEUE IS EMPTY"<<endl;
  else
  {
    for(int i=front+1;i<=rear;i++)
      cout<<arr[i]<<" ";
    cout<<endl;
  }
}
int main()
{
  int choice,n;
  cout<<"------------------------QUEUE OPERATION USING ARRAY-------------------------"<<endl;
  cout<<"1.ENQUEUE\n2.DEQUEUE\n3.FRONT ELEMENT\n4.SIZE OF THE QUEUE\n5.FIND ELEMENT AT INDEX\n6.DISPLAY\n0.EXIT\n";
  cout<<"----------------------------------------------------------------------------"<<endl;
  cout<<"ENTER THE NO OF THE ELEMENTS:";
  cin>>n;
  queue s(n);
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
        cout<<"NO OF ELEMENTS IN A QUEUE:"<<s.size()<<endl;
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
