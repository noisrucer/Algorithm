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