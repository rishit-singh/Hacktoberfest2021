/* Stack implementation using single queue*/
#include<iostream>
#include<queue>
using namespace std;
class Stack {
public:
    queue<int> q1;
    void push(int x);
    int top();
    bool isempty();
    void pop();
    void reverseStack(); // to reverse a stack
    void print(Stack s);
    void stack_size(Stack s);
    };

void Stack::push(int x){
    q1.push(x);
    for(int i=0;i<q1.size()-1;++i){
			q1.push(q1.front());
			q1.pop();
		}
}
void Stack::reverseStack()
    {
        if (q1.empty()) {
            return;
        }

        int fro = q1.front();
        q1.pop();

        reverseStack();

        q1.push(fro);
    }
void Stack::pop(){
    if(q1.empty()){
        cout<<"Stack Underflow"<<endl;
    }
     q1.pop();
}

int Stack::top(){
    if(q1.empty()){
        cout<<"No element available"<<endl;
    }
return q1.front();
}

bool Stack::isempty(){
    return q1.empty();
}

void Stack::print(Stack s){
    Stack temp = s;
    if(temp.isempty()){
        cout<<"Stack is empty"<<endl;
    }
  while(!temp.isempty()){
    cout<<temp.top()<<" ";
    temp.pop();
}
}

void Stack::stack_size(Stack s){
    Stack temp = s;
    int size_count =0 ;
    while(!temp.isempty()){
    size_count++;
    temp.pop();}
    cout<<size_count;
}
