bool res;

int height(Tree* root){
    if(!root) return -1;
    int leftH = height(root->left);
    int rightH = height(root->right);
    if(abs(leftH-rightH) > 1) res = false;
    return 1 + max(leftH,rightH);
}

bool solve(Tree* root) {
    res = true;
    height(root);
    return res;
    
}