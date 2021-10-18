#include<iostream>

using namespace std;

#define n 5


class stack{

    private:
    int *arr;
    int top;

    public:
    stack(){
        arr=new int[n];
        top=-1;
    }

    void push(int x){
        if(top==n-1){
            cout<<"Overflow"<<endl;
        }
        top++;
        arr[top]=x;

    }

    void pop(){
        if(top==-1){
            cout<<"Underflow"<<endl;

        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return arr[top];
    }

    void print(){
        for(int i=0;i<top;i++){
            cout<<arr[i]<<" ";

        }
    }
};


int main(){
    stack s;
    int i , element;
    char cont='y';
    
    do{
    cout<<"Press 1 to push , 2 to pop , 3 to print the stack"<<endl;
    cin>>i;
    cout<<endl;
   
    switch(i){
        case 1:
            cout<<"Enter the element"<<endl;
            cin>>element;
            cout<<endl;
            s.push(element); 
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.print();
            break;
    }
    cout<<"Do you want to continue , press y "<<endl;
    cin>>cont;
    }while(cont=='y');


}