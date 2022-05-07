
void help(Tree* root, int cur,unordered_set<int>&st){
    if(!root) return;
    st.insert(cur);
    help(root->left,cur-1,st);
    help(root->right,cur+1,st);
}
int solve(Tree* root) {
    unordered_set<int>st;
    help(root,0,st);
    return st.size();
}