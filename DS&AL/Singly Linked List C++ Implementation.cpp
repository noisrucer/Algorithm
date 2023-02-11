
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    int key;
    Node* next;
    Node() { //constructor
        data = 0;
        key = 0;
        next = NULL;
    }
    Node(int k, int d) {
        key = k;
        data = d;
    }
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() {
        head=NULL;
    }
    SinglyLinkedList(Node* n) {
        head = n;
    }
    Node* isExist(int k) {
        Node* temp = NULL;
        Node* ptr = head;
        while (ptr != NULL) {
            if (ptr->key == k) temp = ptr;
            ptr = ptr->next;
        }
        return temp; //if temp==NULL ->no matching key:good to go
    }

    void appendNode(Node* n) {
        if (isExist(n->key) != NULL) {
            cout << "Key Already exists. ERROR" << endl;
        }
        else {
            if (head == NULL) {
                head = n;
                cout << "Node Appended" << endl;
            }
            else {
                Node* ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended" << endl;
            }
        }
    }

    void prependNode(Node* n) {
        if (isExist(n->key) != NULL) {
            cout << "Key Already Exists" << endl;
        }
        else {
            if (head == NULL) {
                head = n;
                cout << "Node Appended" << endl;
            }
            else {
                n->next = head;
                head = n;
            }
        }

    }
    void insertAfterKey(int k, Node* n) {
        Node* ptr = isExist(k);
        if (isExist(k) == NULL) {
            cout << "There is no matching input key" << endl;
        }
        else {
            if (isExist(n->key) != NULL) {
                cout << "The Key for your input node already exists" << endl;
            }
            else {
                Node* nextNode = ptr->next;
                if (nextNode == NULL) { //case of one Node or at the end
                    ptr->next = n;
                    cout << "Node Inserted at the end" << endl;
                }
                else {
                    //ptr will return the address of that node so use this for advantage
                    n->next= ptr->next;
                    ptr->next = n;
                    cout << "Node Inserted inbetween" << endl;
                }
            }
        }
    }

    void deleteByKey(int k) {
        Node* ptr = isExist(k);
        if (isExist(k) == NULL) { //if List is empty, then isExist(k) would also be NULL so don't worry about it
            cout << "There is no matching key" << endl;
        }
        else {
            if (head == NULL) {
                cout << "SLL is empty" << endl;
            }
            else {
                //delete at the front
                    //only one element
                if (head->next == NULL) head = NULL;
                else {
                    if (ptr == head) {
                        head = ptr->next;
                    }
                    else {
                        if (ptr->next == NULL) {//at the end
                            Node* temp = head;
                            while (temp->next != ptr) temp = temp->next;
                            temp->next = NULL;
                        }
                        else {//in between
                            Node* temp = head;
                            while (temp->next != ptr) temp = temp->next;
                            temp->next = ptr->next;
                        }
                    }

                    //more than one element

                //delete at the end
                //delete in-betweeen
                }
            }
        }
    }

    void updateNodeByKey(int k, int d) {
        Node* ptr = isExist(k);
        if (ptr == NULL) {
            cout << "no key found" << endl;
        }
        else {
            ptr->data = d;
            cout << "Node Updated" << endl;
        }
    }

    void printlist() {
        if (head == NULL)cout << "List is Empty" << endl;
        else {
            cout << "Singly Linked list Values are: " << endl;
            Node* ptr = head;
            while (ptr != NULL) {
                cout << "[" << ptr->key << "," << ptr->data << "]-> ";
                ptr = ptr->next;
            }
        }
    }
};
int main()
{
    SinglyLinkedList s;
    int option;
    int key1, data1, k1;
    do {
        cout << "\nWhat operation do you want to perform? Select Option Number. Enter 0 to exit" << endl;
        cout << "1. appendNode" << endl;
        cout << "2. prependNode" << endl;
        cout << "3. insertNodeAfter" << endl;
        cout << "4. deleteNodeByKey" << endl;
        cout << "5. updateNodeByKey" << endl;
        cout << "6. print" << endl;
        cout << "7. Clear System" << endl;

        cin >> option;
        Node* n1 = new Node();
        //Node n1;

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            break;
        case 2:
            cout << "Prepend Node Operation \n Enter key & data of the Node to the Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;
        case 3:
            cout << "Insert Node After Operation \n Enter key of existing Node which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter tkey& data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            s.insertAfterKey(k1, n1);
            break;

        case 4:
            cout << "Delete NOde by key operation - \n Enter key  to be updated" << endl;
            cin >> k1;
            s.deleteByKey(k1);
            break;

        case 5:
            cout << "UPdate Node by key operation - \n Enter key & new data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);
            break;
        case 6:
            s.printlist();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter proper option number" << endl;

        }
    } while (option != 0);

    return 0;
    
}