#include <iostream>
using namespace std;
struct Node
{
    int val;
    int key;
    Node *next;
    Node(){
        val = 0;
        key = 0;
        next = NULL;
    }

    Node(int key, int val){
        this->val = val;
        this->key = key; 
    }
};

class SinglyLinkedList{
public:
    Node* head;
    SinglyLinkedList(){
        head = NULL;
    }

    SinglyLinkedList(Node *n){
        head = n;
    }

    //1. Check if node exists with the key
    Node* nodeExist(int k){
        Node *check = NULL, *cur = head;
        if(!head) return NULL; //if LL is empty, return NULL
        while(cur){
            if(cur->key == k) check = cur; //When the key matches, update check pointer
            cur = cur->next;
        }
        return check;
    }

    //2. Append to the end
    void appendNode(Node *node){
        if(nodeExist(node->key)){ //If the same key exists, terminate
            cout<<"Node already exists with the same key!\n";
            return;
        }

        Node *temp = head;
        if(!temp) head=node; //Wnen there's nothing
        else{
            while(temp->next) temp = temp->next; //traver until the end
            temp->next = node; //connect
            cout<<"Node Appended Successfully!\n";
        }
    }

    //3. Prepend Node
    void prependNode(Node *node){
        if(nodeExist(node->key)){ //if same key exists, terminate
            cout<<"Node already exists with the same key!\n";
            return;
        }

        node->next = head; //this covers the case when the head is NULL as well. Think about that.
        head = node;
        cout<<"Node prepended successfully!\n";
    }

    //4. insertNodeAfterKey
    void insertNodeAfterKey(int k, Node* node){
        Node* spot = nodeExist(k);
        if(!spot){ //When LL is empty or has no matching key
            cout<<"No Node with the key exists!\n";
            return;
        }
        //LL is not empty and has the matching key
        node->next = spot->next; // A(spot)->B(spot->next)
        spot->next = node;       //        node
        cout<<"Node Inserted Successfully!\n";
    }

    //5. Delete Node by Key
    void deleteByKey(int k){
        Node* spot = nodeExist(k);
        if(!spot){ //if head is NULL or no matching key
            cout<<"No Node with the key exists!\n";
            return;
        }

        if(spot==head) head = head->next; //When target node is head,  head = head -> next
        else{ 
            Node* temp = head;
            while(temp->next != spot) temp=temp->next; // A -> temp -> spot -> B -> C
            temp->next = spot->next;
        }
    }

    void printList(){
        Node *temp = head;
        while(temp){
           cout<<"{"<<temp->key<<","<<temp->val<<") -> ";
           temp = temp -> next;
        }
        cout<<"\n";
    }
};
int main(){
    SinglyLinkedList s;
    Node* node1 = new Node(1,10);
    s.appendNode(node1);

    Node* node2 = new Node(2,15);
    s.appendNode(node2);

    Node* node3 = new Node(132,15);
    s.appendNode(node3);

    Node* node4 = new Node(13,999);
    s.prependNode(node4);

    s.deleteByKey(2);
    s.deleteByKey(132);
    s.deleteByKey(13);

    s.insertNodeAfterKey(1, new Node(41,22));
    s.printList();
}