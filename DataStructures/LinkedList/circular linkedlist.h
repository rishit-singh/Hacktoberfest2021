#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
  public:
  int data;
  Node * next;
  Node()
  {
    data=0;
    next=NULL;
  }
  Node(int d)
  {
    data=d;
    next=NULL;
  }
};
class CircularLinkedlist
{
  public:
  Node *head;
  CircularLinkedlist()
  {
    head=NULL;
  }
  ~CircularLinkedlist()
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
int CircularLinkedlist::length()
{
    if(head==NULL) return 0;
    Node *p=head;
    int len=0;
    do{
      len++;
      p=p->next;
    }while(p!=head);
    return len;
}
void CircularLinkedlist::createNode(int A[],int n)
{
    Node *p=new Node(A[0]);
    Node *t;
    if(head==NULL)
    {
      head=p;
      p->next=head;
      for (int i=1;i<n;i++)
      {
          t=new Node(A[i]);
          p->next=t;
          t->next=head;
          p=t;
      }
    }
    else
    {
      p=head;
      while(p->next!=head)
        p=p->next;
      for (int i=0;i<n;i++)
      {
        t=new Node(A[i]);
        p->next=t;
        t->next=head;
        p=t;
      }
    }
  }
void CircularLinkedlist::display()
{
    if(head==NULL)
      cout<<"LINKEDLIST IS EMPTY\n";
    else
    {
    cout<<"ELEMENTS PRESENT IN THE LINKEDLIST:";
     Node *p=head;
    do{
    cout<<p->data<<" ";
     p=p->next;
    }while(p!=head);
    cout<<endl;
    }
}
void CircularLinkedlist::update(int x,int d)
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
        cout<<"ELEMENT WAS UPDATED FROM "<<k<<" TO "<<d<<" IN INDEX "<<x<<endl;
    }
}
int CircularLinkedlist::prepend(Node * n)
{
    if(head==NULL)
    {
      head=n;
      n->next=head;
    }
    else
    {
        Node * p=head;
        while(p->next!=head)
          p=p->next;
        p->next=n;
        n->next=head;
        head=n;
    }
    return n->data;
}
int CircularLinkedlist::append(Node * n)
{
    if(head==NULL)
    {
        head=n;
        n->next=head;
    }
    else
    {
        Node * p=head;
        while(p->next!=head)
            p=p->next;
        p->next=n;
        n->next=head;
    }
    return n->data;
}
int CircularLinkedlist::deleteNode(int x)
{
    if (head==NULL)
    {
      cout<<"LINKEDLIST IS ALREADY EMPTY\n";
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
              while(p->next!=head)
              {
                p=p->next;
              }
              l=head->data;
              if(p==head)
              {
                  delete head;
                  head=NULL;
              }
              else
              {
                  p->next=head->next;
                  delete head;
                  head=p->next;
              }
              return l;
            }
            else
            {
                p=head;
                for(int i=0;i<x-1;i++)
                  p=p->next;
                q=p->next;
                l=q->data;
                p->next=q->next;
                delete q;
                return l;
            }
        }
    }
}
int CircularLinkedlist::insert(int x,Node * n)
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
        p->next=n;
        return n->data;
      }
    }
}
