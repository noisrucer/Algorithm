vector<int>res;

void helper(Tree* root, int level){
    if(!root) return;
    if(res.size() < level + 1) res.push_back(root->val);
    else res[level] += root->val;

    helper(root->left, level+1);
    helper(root->right, level);
}

vector<int> solve(Tree* root) {
    res.clear();    
    helper(root,0);
    return res;
}