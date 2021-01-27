/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* dfs(Tree* root){
    if(!root) return NULL;
    if((root->left && root->right) || (root->left==root->right)){
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        return root;
    }
    else if(root->left){
        return dfs(root->left);
    }else{
        return dfs(root->right);
    }
} 
Tree* solve(Tree* root) {
    return dfs(root);
    
}

//2
Tree* dfs(Tree* root){
    if(!root) return NULL;
    if(root->left==root->right) return root;
    root->left = dfs(root->left);
    root->right = dfs(root->right);
    if(root->left && root->right) return root; //only one child

    if(root->left) return root->left;
    else return root->right;
    
} 
Tree* solve(Tree* root) {
    return dfs(root);
    
}