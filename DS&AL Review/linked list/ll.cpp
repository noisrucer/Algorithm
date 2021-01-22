#include <iostream>
using namespace std;

struct Node{
    int key;
    int val;
    Node* next;
    Node(){
        val = 0;
        key = 0;
        next = NULL;
    }

    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};

class SinglyLinkedList{
    private:
        Node* head;
    public:
        SinglyLinkedList(){
            head = NULL;
        }
        bool isEmpty();
        Node* nodeExist(int key);
        void appendNode(Node* node);
        void prependNode(Node* node);
        void insertAfterKey(Node* node, int key);
        void deleteByKey(int key);
        void printList();
};


   bool SinglyLinkedList::isEmpty(){
       return head == NULL;
   }

   Node* SinglyLinkedList::nodeExist(int key){
       Node *target = NULL, *temp = head;
    //    cout<<temp->val<<endl;
       while(temp){
           if(temp->key == key){
               target = temp;
               break;
           }
           temp = temp->next;
       }
       return target;
   }

   void SinglyLinkedList::appendNode(Node* node){
       if(nodeExist(node->key)){
           cout<<"node already exists!n";
           return;
       }
       if(isEmpty()) head = node;
       else{
           Node* temp = head;
           while(temp->next){
               temp = temp->next;
           }
           temp->next = node;
       }
    //    cout<<head->val<<" ";
       cout<<"Appended Successfully!\n";
   }

   void SinglyLinkedList::prependNode(Node* node){
       if(nodeExist(node->key)){
           cout<<"node already exists!n";
           return;
       }
       node->next = head;
       head = node;
    //    cout<<head->val<<" ";
       cout<<"Prepended Successfully!\n";
   }

   void SinglyLinkedList::insertAfterKey(Node* node, int key){
       Node* target = nodeExist(key);
       if(!target){
           cout<<"Linked List is empty or no such key exists!\n";
           return;
       }
       node->next = target->next;
       target->next = node;
       cout<<"Inserted Successfully!\n";
   }

   void SinglyLinkedList::deleteByKey(int key){
       Node* target = nodeExist(key);
       
       if(!target){
           cout<<"Linked List is empty or no such key exists!\n";
           return;
       }
       if(target == head) head = head->next;  //CAREFUL!!! if the target is in the front(only one node or multiple nodes) careful!!
       else{
           Node* temp = head;
           while(temp->next != target) temp = temp->next;
           temp->next = target->next;
       }
       cout<<"Deleted Successfully!\n";
   }

   void SinglyLinkedList::printList(){
       Node* temp = head;
       while(temp){
           cout<<"("<<temp->key<<","<<temp->val<<") -> ";
           temp = temp->next;
       }
       cout<<"\n";
   }

int main(){
    SinglyLinkedList s;
    Node* node1 = new Node(1,10);
    s.appendNode(node1);
 s.printList();
    Node* node2 = new Node(2,15);
    s.appendNode(node2);
 s.printList();
    Node* node3 = new Node(132,15);
    s.appendNode(node3);
 s.printList();
    Node* node4 = new Node(13,999);
    s.prependNode(node4);
 s.printList();
    s.deleteByKey(13);
    s.deleteByKey(2);
    s.deleteByKey(23);
    s.printList();
}