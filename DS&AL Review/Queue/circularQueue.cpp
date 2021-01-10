#include <iostream>
using namespace std;
const int MAX = 10;
class CircularQueue{
    private:
        int front;
        int rear;
        int arr[MAX]{};
    public:
        CircularQueue(){ //Queue constructor. Initial positions of front/rear = -1
            front=rear=-1;
        }

        bool isEmpty(){
            return front==-1 && rear==-1;
        }

        bool isFull(){
            return (rear+1)%MAX==front;
        }

        void enqueue(int x){
            if(isFull()){ //when full, can't add
                cout<<"Queue is Full!\n";
                return;
            }
            else if(isEmpty()){ //when empty, set front/rear to 0
                front=rear=0;
            }
            else{ //circular queue - modular operations
                rear = (rear+1) % MAX;
            }

            arr[rear] = x;
        }

        int dequeue(){
            int popVal;
            if(isEmpty()){
                cout<<"Queue is Empty!\n";
                return 0;
            }
            else if(front==rear){ //when there's one element, reset front/rear to -1
                popVal = arr[front];
                arr[front]=0;
                front=rear=-1;
            }
            else{
                popVal = arr[front];
                front = (front+1)%MAX;
            }
            return popVal;
        }

        int count(){
            if(isEmpty()) return 0;
            if(front<=rear) return rear-front+1; 
            else return rear+MAX-front+1;
            
        }
};

int main(){
    CircularQueue Q;
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(7);
    Q.enqueue(8);
   
    cout<<Q.dequeue()<<endl; //3
    cout<<Q.dequeue()<<endl; //4
    cout<<Q.dequeue()<<endl; //5
    cout<<Q.count()<<endl; //3
}