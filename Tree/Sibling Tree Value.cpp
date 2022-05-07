/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

//1st Approach
int solve(Tree* root, int k) {
    while(1){
        if(root->val == k) return 0;
        if(root->val < k){
            if(root->right->val==k) return root->left->val;
            root = root->right;
        }
        if(root->val > k){
            if(root->left->val==k) return root->right->val;
            root = root->left;
        }
    }
    return 0;
}

//2nd Approach -> tightrope
int res;
void dfs(Tree* root, int k){
   if(root->left == root->right) return;
   if(root->left->val == k){
       res = root->right->val;
       return;
   }
   if(root->right->val==k){
       res = root->left->val;
       return;
   }
   if(k>root->val) dfs(root->right,k);
   else dfs(root->left,k);
}
int solve(Tree* root, int k) {
    dfs(root,k);
    return res;
}