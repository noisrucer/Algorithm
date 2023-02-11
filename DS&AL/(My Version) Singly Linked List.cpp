
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }
 };

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = NULL;
    }
    Node* isDataExist(int d) {
        Node* ptr = NULL;
        
       
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == d) {
                ptr = temp;
            }
            temp = temp->next;
        }
        return ptr; //ptr=NULL이면 존재하지 않는것, ptr!=NULL이면 존재하는것
    }
   
    void appendNode(Node* n) {
        if (head == NULL) {
            head = n;
            cout << "Append Complete1" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        cout << "Append Copmlete" << endl;

    }
    void deleteNode(int d) {
        Node* ptr = isDataExist(d);
        if (ptr==NULL) {//!ptr?
            cout << "Matching Data does not exist!\n";
            return;
        }
        //if it's not NULL -> data exist -> at least one element
        if (head->data == d) {//맨앞에 있을때
            head = head->next;
            cout << "Delete Complete\n";
        }
        else {//맨앞에 있지 않을때->중간 혹은 맨끝
            if (ptr->next == NULL) {//맨끝
                Node* temp = head;
                while (temp->next != ptr) {
                    temp = temp->next;
                } //temp가 ptr바로 앞에 도달하면
                temp->next = NULL;
                cout << "Delete Complete\n";
            }
            else { //중간
                Node* temp = head;
                while (temp->next != ptr) {
                    temp = temp->next;
                } //temp가 ptr바로 앞에 도달하면
                temp->next = ptr->next;
                cout << "Delete Complete\n";
            }
        }

    }
    void printlist() {
        Node* temp = head;
        cout << "Singly Linked List Values: " << "\n";
        while (temp!= NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
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
            cin >> data1;
            n1->data = data1;
            s.appendNode(n1);
            break;
        /*case 2:
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
            */
        case 4:
            cout << "Delete NOde by key operation - \n Enter key  to be updated" << endl;
            cin >> data1;
            s.deleteNode(data1);
            break;
            /*
        case 5:
            cout << "UPdate Node by key operation - \n Enter key & new data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);
            break;*/
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
