/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int VAL(Tree* root){return root ? root->val : 0;}

bool helper(Tree* root){
    if(!root || (!root->left && !root->right)) return true;
    return VAL(root)==VAL(root->left)+VAL(root->right) && helper(root->left) && helper(root->right);
}

bool solve(Tree* root) {
    return helper(root);
}