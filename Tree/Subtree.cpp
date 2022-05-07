/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool isSubtree(Tree* root, Tree* target){
    if(!root && !target) return true;
    if(!root || !target) return false;
    return (root->val == target->val && isSubtree(root->left, target->left) && isSubtree(root->right, target->right)) || isSubtree(root->left, target) || isSubtree(root->right, target);
}
bool solve(Tree* root, Tree* target) {
    return isSubtree(root, target);
}

bool solve(Tree* root, Tree* target) {
    if (root == NULL and target == NULL) return true;
    if (root == NULL and target != NULL) return false;
    if (root != NULL and target == NULL) return false;
    if (root->val == target->val)
        return solve(root->left, target->left) and solve(root->right, target->right);
    if (root->val != target->val) return solve(root->left, target) or solve(root->right, target);
    return false;
}