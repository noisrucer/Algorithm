/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

//faster - O(n)
Tree* solve(Tree* root) {
    if(!root) return nullptr;
    root->left = solve(root->left);
    root->right = solve(root->right);
    if(root->left == root->right) return root->val & 1 ? root : nullptr;
    return root;
}


//slower
Tree* del(Tree* root){
    if(!root) return nullptr;
    Tree* leftNode = del(root->left), *rightNode = del(root->right);
    
    if(leftNode && leftNode->val%2==0 && !leftNode->left && !leftNode->right) root->left = nullptr;
    if(rightNode && rightNode->val%2==0 && !rightNode->left && !rightNode->right) root->right = nullptr;

    return root;
}

Tree* solve(Tree* root) {
    if(!root) return nullptr;
    Tree* head = del(root);
    if(!root->left && !root->right && root->val%2==0) return nullptr;
    return head;
}