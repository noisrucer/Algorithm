
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
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
		root = GetNewNode(data);
		
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
	else if (data <= root->data) Search(root->left, data);
	else Search(root->right,data);
}

int FindMin_iteration(Node* root) {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
		return -1;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}
int FindMin_recursion(Node* root) {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	FindMin_recursion(root->left);
}
int FindHeight(Node* root) {
	if (root == NULL) {
		return -1;
	}
	return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}
void LevelOrder(Node* root) {
	if (root == NULL) return;
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty()) {
		int queueCount = Q.size();
		while (queueCount > 0) {
			Node* temp = Q.front();
			cout << temp->data << " ";
			Q.pop();
			if (temp->left != NULL) Q.push(temp->left);
			if (temp->right != NULL) Q.push(temp->right);
			queueCount--;
		}cout << endl;
	}
}
int main()
{
	Node* root = NULL;
	root = insert(root, 15); root = insert(root, 10);
	root = insert(root, 20); root = insert(root, 25);
	root = insert(root, 8); root = insert(root, 12);
	root = insert(root, 6);
	root = insert(root, 4);
	root = insert(root, 1);
	root = insert(root, 9);
	
	LevelOrder(root);
	

	
}
