
#include <iostream>
using namespace std;
class Node {
public:
    int key;
    int data;
    Node* next;
    Node* previous;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
    }
};
    class DoublyLinkedList {
    public:
        Node* head;

        DoublyLinkedList() {
            head = NULL;
        }
        DoublyLinkedList(Node* n) {
            head = n;
        }

        //1. existence of node
        Node* nodeExists(int k) {
            Node* temp = NULL;
            Node* ptr = head;

            while (ptr != NULL) {
                if (ptr->key == k) {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }

        //2. Append a node to the list
        void appendNode(Node* n) {
            if (nodeExists(n->key) != NULL) {
                cout << "NOde already exists with key value " << n->key << endl;
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
                    n->previous = ptr;
                    cout << "Node Appended" << endl;
                }
            }
        }
        void prependNode(Node* n) {
            if (nodeExists(n->key) != NULL) {
                cout << "Node already exists with the same key value " << n->key << endl;
            }
            else {
                if (head == NULL) {
                    head = n;
                    cout << "Node Appended" << endl;
                }
                else {
                    head->previous = n;
                    n->next = head;//link the lines first and then
                    head = n; //set the head value and address
                    cout << "Node Prepended" << endl;
                }
            }
        }

        void insertNodeAfterByKey(int k, Node* n) {
            Node* ptr = nodeExists(k); //if it exists, it returns the address to pointer after which you add another node
            if (ptr == NULL) {
                cout << "No node exists with key value: " << k << endl;
            }
            else {
               if( nodeExists(n->key)!=NULL) {
                   cout << "NOde already exists with the same key value " << n->key << endl;
               }
               else {
                   Node* nextNode = ptr->next;
                   if (nextNode == NULL) {
                       ptr->next = n;
                           n->previous = ptr;
                           cout << "Node Inserted at the End" << endl;
                   }
                   else {
                       cout << "Inserting Node OPeration" << endl;
                       n->previous = ptr;
                       ptr->next = n;
                       n->next = ptr->next;
                       ptr->next->previous = n;

                       cout << "Node Inserted In Between" << endl;
                   }
               }
            }
        }

        void deleteNodeByKey(int k) {
            Node* ptr = nodeExists(k);
            int* temp;
            if (ptr == NULL) {
                cout << "No node exists with the matching key " << k << endl;
            }
            else {
                if (head == NULL) {
                    cout << "DLL is Empty" << endl;
                }
                else if(head!=NULL){
                    if (head->key == k) {
                        head = head->next;
                        cout << "Node Unlinked with keys value: " << k << endl;
                    }
                    else {
                        Node* nextNode = ptr->next;
                        Node* prevNode = ptr->previous;
                        if (nextNode == NULL) {//at the end
                            prevNode->next = NULL;
                            cout << "Node Deleted at the END" << endl;
                        }
                        else {//in between
                            prevNode->next = nextNode;
                            nextNode->previous = prevNode;
                            cout << "Node delete In Between" << endl;
                        }
                    }
                    
                }
            }
        }

        //6. Update node by key
        void updateNodeByKey(int k, int d) {
            Node* ptr = nodeExists(k);
            if (ptr == NULL) {
                cout << "No node exists with the matching key " << k << endl;
            }
            else {
                ptr->data = d;
                cout << "Node Data Updated" << endl;
            }
        }

        //7. Printing
        void printList() {
            if (head == NULL) {
                cout << "No NOde exists in DLL" << endl;
            }
            else {
                cout << "Doubly Linked List Values: ";
                Node* ptr = head;
                while (ptr != NULL) {
                    cout << "(" << ptr->key << "," << ptr->data << ") --> ";
                    ptr = ptr->next;
                }
            }
        }


    };

int main()
{
    DoublyLinkedList s;
    int option;
    int key1, k1, data1;
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

            s.insertNodeAfterByKey(k1, n1);
            break;

        case 4:
            cout << "Delete NOde by key operation - \n Enter key  to be updated" << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;

        case 5:
            cout << "UPdate Node by key operation - \n Enter key & new data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);
            break;
        case 6:
            s.printList();
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
