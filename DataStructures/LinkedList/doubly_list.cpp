#include<iostream>
using namespace std;
struct Node{
  int data;
   struct Node *prev,*next;
};
struct Node *first,*last;
                                                  /* insert at begin*/
void insert_begin(int d){
  Node *p=new Node;
  p->data=d; p->prev=NULL;
  if(first==NULL){
    first=p; last=p;
    cout<<"Node inserted\n";
    return;
  }
  else{
    p->next=first;
    first->prev=p;
    first=p;

  }
  cout<<"Node inserted at begin\n";

}
                                                  /*insert at last*/
void insert_last(int d){
   Node *p=new Node;
   p->data=d; p->next=NULL;
   if(first==NULL){
    first=p; last=p;
    cout<<"Node inserted\n";
    return;
   }
   else{
        Node*t=first;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=p; p->prev=t; last=p;
   }
   cout<<"Node inserted at last \n";

}
/*insert before node*/
void insert_beforeN(int d,int v){
    Node *p=new Node;
    p->data=v;
    Node *t=first;
    while(t->data==d){
        t=t->next;
    }
    if(t->prev==NULL){
        p->next=t; t->prev=p; first=p;
    }
    else{
        p->next=t;
        p->prev=t->prev;
         t->prev->next=p;
         t->prev=p;
    }
   cout<<"inserted\n";
}




                                                 /*display function*/
void display(){
   Node *t=first;
   if(first==NULL){
    cout<<"list is empty......";
   }
   else{
     cout<<"list contains>>> ";
   while(t!=NULL){
    cout<<t->data<<",";
    t=t->next;
   }

   }

}
int main(){
        insert_begin(4); //fucntion to insert a node at beginning
        insert_begin(6);
        insert_last(8);  //fucntion to insert a node at last 
        insert_beforeN(6,5);// fucntion to insert a node before a specific node
         display();
}
