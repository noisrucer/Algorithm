
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};
Node* GetNewNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* insert(Node* root, int data) {
	if (root == NULL) {
		root= GetNewNode(data);
		
	}
	else if (data <= root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
}

bool Search(Node* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);

}
int Findmin_iteration(Node* root) {
	if (root == NULL) {
		cout << "error" << endl;
		return -1;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}
int Findmin_recursion(Node* root) {
	if (root == NULL) {
		cout << "error" << endl;
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	Findmin_recursion(root->left);
}
int FindHeight(Node* root) {
	if (root == NULL)
		return -1;
	return max(FindHeight(root->left),FindHeight(root->right))+1;
}
int main()
{
	Node* root= NULL;
	root = insert(root, 15); root = insert(root, 10);
	root = insert(root, 20); root = insert(root, 25);
	root = insert(root, 8); root = insert(root, 12);
	root = insert(root, 6);
	root = insert(root, 4);
	root = insert(root, 1);
	root = insert(root, 9);
	int number;
	cout << "enter number for search";
	cin >> number;
	if (Search(root, number) == true) cout << "found\n";
	else cout << "not found\n";
	cout<<FindHeight(root);

}
