/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void dfs(Tree* root, int level, pair<int,int>&deep){
    if(!root) return;
    if(level > deep.first){
        deep.second =  root->val;
        deep.first = level;
    }
    dfs(root->left, level+1,deep);
    dfs(root->right, level+1,deep);
}

int solve(Tree* root) {
    pair<int,int>deep={0,root->val};
    dfs(root,0,deep);
    return deep.second;
}