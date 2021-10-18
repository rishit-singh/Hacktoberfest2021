#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node * previous; Node()
    {
      data=0;
      previous=NULL;
      next=NULL;
    }
    Node(int d)
    {
      data=d;
      previous=NULL;
      next=NULL;
    }
  };
class DoublyLinkedlist
{
  public:
  Node *head;
  DoublyLinkedlist()
  {
    head=NULL;
  }
  ~DoublyLinkedlist()
  {
     delete head;
  }
    void createNode(int A[],int);
    int append(Node *);
    int prepend(Node *);
    int insert(int,Node *);
    int deleteNode(int);
    void update(int,int);
    void display();
    int length();
};
int DoublyLinkedlist::length()
{
    if(head==NULL) return 0;
    Node *p=head;
    int len=0;
    while(p)
    {
    len++;
    p=p->next;
    }
    return len;
}
void DoublyLinkedlist::createNode(int A[],int n)
{
    Node *p=new Node(A[0]);
    Node *t;
    if(head==NULL)
    {
        head=p;
        head->next=head->previous=NULL;
        for (int i=1;i<n;i++)
        {
          t=new Node(A[i]);
          t->next=NULL;
          t->previous=p;
          p->next=t;
          p=t;
        }
      }
      else
      {
          p=head;
          while(p->next!=NULL)
            p=p->next;
          for (int i=0;i<n;i++)
          {
            t=new Node(A[i]);
            t->next=NULL;
            t->previous=p;
            p->next=t;
            p=t;
          }
      }
}
int DoublyLinkedlist::deleteNode(int x)
{
  if (head==NULL)
  {
    cout<<"LINKED LIST IS ALREADY EMPTY";
    return -1;
  }
  else
  {
      if(x<0 || x>length()-1)
      {
          cout<<"INVALID INDEX\n";
          return -1;
      }
      else
      {
          int l;
          Node *p,*q;
          if(x==0)
          {
             p=head;
             head=head->next;
             l=p->data;
             delete p;
             return l;
          }
          else
          {
              p=head;
              for(int i=0;i<x;i++)
                  p=p->next;
              l=p->data;
              p->previous->next=p->next;
              if(p->next)
                 p->next->previous=p->previous;
              delete p;
              return l;
            }
          }
        }
      }
int DoublyLinkedlist::append(Node * n)
{
    if(head==NULL)
    {
      head=n;
      head->next=head->previous=NULL;
    }
    else
    {
      Node * p=head;
      while(p->next!=NULL)
       p=p->next;
      p->next=n;
      n->previous=p;
    }
    return n->data;
}
int DoublyLinkedlist::prepend(Node * n)
{
  if(head==NULL)
  {
    head=n;
    n->next=n->previous=NULL;
  }
  else
  {
    head->previous=n;
    n->next=head;
    head=n;
  }
  return n->data;
}
int DoublyLinkedlist::insert(int x,Node * n)
{
    if(x<0 || x>length())
    {
      cout<<"INVALID INDEX\n";
      return -1;
    }
    else
    {
      if(x==0)
        return prepend(n);
      else if(x==length())
        return append(n);
      else
      {
          Node * p=head;
          for(int i=0;i<x-1;i++)
            p=p->next;
          n->next=p->next;
          p->next->previous=n;
          p->next=n;
          n->previous=p;
          return n->data;
        }
      }
    }
void DoublyLinkedlist::update(int x,int d)
{
    if(x<0 || x>length())
      cout<<"INVALID INDEX\n";
    else
    {
        int k;
        Node *p=head;
        for(int i=0;i<x;i++)
        p=p->next;
        k=p->data;
        p->data=d;
        cout<<"ELEMENT WAS UPDATED FROM "<<k<<" to "<<d<<" IN INDEX "<<x<<endl;
    }
}
void DoublyLinkedlist::display()
{
  if(head==NULL)
    cout<<"LINKED LIST IS EMPTY.\n";
  else
  {
      cout<<"ELEMENTS PRESENT IN LINKEDLIST:";
       Node *p=head;
      while(p)
      {
        cout<<p->data<<" ";
        p=p->next;
      }
      cout<<endl;
    }
}
int main()
{
  cout<<"- ----------------------------------------------------------"<<endl;
  cout<<"INDEX STARTS FROM 0 ONWARDS	\n";
  DoublyLinkedlist c;
  cout<<"1.CREATE A LIST OR APPEND MANY ELEMENTS\n2.APPEND A NODE\n3.PREPEND A NODE\n4.INSERT A NODE\n5.DELETE A NODE\n6.UPDATE A NODE\n7.LENGTH OF LIST\n8.DISPLAY THE ELEMENTS\n0.EXIT\n";
  int option;
  option=1;
  do{
      cout<<"\n------------------------------------------------------"<<endl;
      cout<<"\nENTER YOUR OPTION:";
      cin>>option;
      Node * v=new Node();
      switch(option)
      {
      case 0:
        cout<<"EXITING………….";
        break;
      case 1:
      {
      int n;
      cout<<"ENTER THE NO OF ELEMENTS TO BE INSERTED:";
      cin>>n;
      int A[n];
      cout<<"ENTER THE ELEMENTS TO BE INSERTED\n";
      for(int i=0;i<n;i++)
      {
      cout<<"ELEMENT "<<i+1<<":";
      cin>>A[i];
      }
      c.createNode(A,n);
       break;
      }

      case 2:
      {
      cout<<"ENTER THE DATA TO BE APPENDED:";
      cin>>v->data;
      cout<<"APPENDING ELEMENT:"<<c.append(v)<<endl;
       break;
      }
      case 3:
      {
      cout<<"ENTER THE DATA TO BE PREPENDED:";
      cin>>v->data;
      cout<<"PREPENDING ELEMENT:"<<c.prepend(v)<<endl;
      break;
      }
      case 4:
      {
        int x;
        cout<<"ENTER THE DATA TO BE INSERTED:";
        cin>>v->data;
        cout<<"ENTER THE INDEX WHERE TO BE INSERTED:";
        cin>>x;
        cout<<"INSERTING ELEMENT:"<<c.insert(x,v)<<endl;
         break;
      }
      case 5:
      {
        int x;
        cout<<"ENTER THE INDEX TO BE DELETED:";
        cin>>x;
        cout<<"DELETING ELEMENT:"<<c.deleteNode(x)<<endl;
        break;
      }
      case 6:
      {
          int x,d;
          cout<<"ENTER THE DATA TO BE UPDATED:";
          cin>>d;
          cout<<"ENTER THE INDEX WHERE TO BE UPDATED:";
          cin>>x;
          c.update(x,d);
          break;
      }
      case 7:
        cout<<"LENGTH OF THE LINKEDLIST:"<<c.length()<<endl;
        break;
      case 8:
        c.display();
        break;
      default:
        cout<<"ENTER VALID OPTION"<<endl;
    }
}while(option!=0);
  return 0;
}
