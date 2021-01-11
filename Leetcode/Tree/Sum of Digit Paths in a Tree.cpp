/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int dfs(Tree*root, int sum){
    if(!root) return 0;
    if(root->left == root->right) return sum+root->val;
    return dfs(root->left, (root->val+sum)*10) + dfs(root->right, (root->val+sum)*10);
    
}
int solve(Tree* root) {
    return dfs(root,0);
}