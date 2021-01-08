//Stack Operations
// push() pop() isEmpty() isFull() count() peek() change() display()
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000;

class Stack{
    private:
        int top;
        int arr[MAX]; //max size of stack
    public:
        Stack(){ //constructor
            top = -1;
        }

        bool isEmpty(){
            return top == -1;
        }

        bool isFull(){
            return top == MAX - 1;
        }

        void push(int x){
            if(this->isFull()){
                cout<<"Stack Overflow!\n";
                return;
            }
            arr[++top] = x;
        }

        int pop(){
            if(this->isEmpty()){
                cout<<"Stack Underflow!\n";
                return -1;
            }
            return arr[top--]; //If we want to reset to popped box to zero, then do it but here, only the position of the top matters
        }

        int peek(){
            if(this->isEmpty()){
                cout<<"Stack is Empty!\n";
                return -1;
            }
            return arr[top];
        }

        int count(){
            return top+1;
        }
};

int main(){
    Stack s1;
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<s1.peek()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.count()<<endl;
}
