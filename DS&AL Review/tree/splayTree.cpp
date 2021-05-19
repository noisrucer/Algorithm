#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node(){
        left = NULL;
        right = NULL;
    }
    Node(int key){
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

//leftRotate without parent pointers
//This is self-explanatory
Node* leftRotate(Node* x){
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

//rightRotate without parent pointers
//This is self-explanatory
Node* rightRotate(Node* x){
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node* splay(Node* root, Node* x){
    //if it's NULL or the current node's key is equal to the the target node's value, return the root
    //Imagine for the first splay operation, the root->key == target->key, we don't have to do anything
    if(root->key == x->key || !root) return root; 

    //when the target's key is less than the root's key, it means the target is somewhere in the left-subtree -> zig
    if(x->key < root->key){ 
        // if(!root->left) return root; //key is not present
        //If the target is somewhere in the left-left subtree of the root
        if(x->key < root->left->key){ //Zig-Zig -> Perform ONE rightRotation
            root->left->left = splay(root->left->left, x); //splay root->left->left
            root = rightRotate(root);
        }
        //If the target is somewhere in the left-right subtree of the root
        else if(x->key > root->left->key){ //Zig-Zag -> Perform ONE leftRotation
            root->left->right = splay(root->left->right, x);
            root->left = leftRotate(root->left);
        }
        
        //If the target doesn't fall any of those two if, else if statements, we can just perform only one rotation.
        return rightRotate(root); //second rightRotation
        //Above logics are exactly the same in symmetry for the else block below.
    }

    else{
        // if(!root->right) return root;
        if(x->key > root->right->key){ //Zag-Zag -> Perform ONE leftRotation
            root->right->right = splay(root->right->right,x);
            root = leftRotate(root);
        }
        else if(x->key < root->right->key){ //Zag-Zig -> Perform ONE rightRotation
            root->right->left = splay(root->right->left, x);
            root->right = rightRotate(root->right);
        }

        return leftRotate(root); //second leftRotation
    }
}

Node* insertNode(Node* root, Node* newNode){
    if(!root) return newNode;
    Node* y = NULL;
    Node* x = root;
    
    while(x){
        y = x;
        if(newNode->key < x->key) x = x->left;
        else x = x->right;
    }

    if(newNode->key < y->key){
        y->left = newNode;
    }else{
        y->right = newNode;
    }
    
    return splay(root, newNode);
}

void preorder(Node* root){
    if(!root) return;
    preorder(root->left);
    cout<<root->key<<" ";
    preorder(root->right);
}

int main(){
    Node* root = NULL;
    root = insertNode(root, new Node(5));
    root = insertNode(root, new Node(7));
    root = insertNode(root, new Node(1));
    root = insertNode(root, new Node(3));
    root = insertNode(root, new Node(9));
    root = insertNode(root, new Node(8));
    root = insertNode(root, new Node(6));

    preorder(root);
}