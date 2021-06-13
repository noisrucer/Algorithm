
int sum = 0;
void help(Tree* root){
    if(!root) return;
    help(root->right);
    sum += root->val;
    root->val = sum;
    help(root->left);
}

Tree* solve(Tree* root) {
    sum = 0;
    help(root);
    return root; 
}