#include <iostream>
using namespace std;
const int MAX=10;
class Queue{
    private:
        int front;
        int rear;
        int arr[MAX]{};
    public:
        Queue(){
            front = rear = -1;
        }

        bool isEmpty(){
            return front==-1 && rear==-1;
        }

        bool isFull(){
            return rear==MAX-1;
        }

        void enqueue(int x){
            if(isFull()){
                cout<<"Queue is Full!\n";
                return;
            }
            else if(isEmpty()){
                front=rear=0;
            }
            else{
                rear++;
            }
            arr[rear]=x;
        }

        int dequeue(){
            int pop;
            if(isEmpty()){
                cout<<"queue is empty!\n";
                return 0;
            }
            else if(front==rear){
                pop = arr[rear];
                arr[rear]=0;
                front=rear=-1;
            }
            else{
                pop = arr[front];
                arr[front]=0;
                front++;
            }
            return pop;
        }

        int count(){
            return rear==-1 && front==-1 ? 0 : rear-front+1;
        }
};

int main(){
    Queue Q;
    Q.enqueue(1);
    Q.enqueue(3);
    Q.enqueue(5);
    cout<<Q.count()<<endl;
    cout<<Q.dequeue()<<endl;
    cout<<Q.dequeue();
    cout<<Q.dequeue();
    cout<<Q.count()<<endl;
}