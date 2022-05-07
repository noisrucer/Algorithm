
int cnt=0;
int helper(Tree* root){
 if(!root) return INT_MIN;
    int cur_max = max({root->val,helper(root->left),helper(root->right)});
    if(root->val==cur_max) cnt++;
    return cur_max;
}
int solve(Tree* root) {
   cnt=0;
   helper(root);
   return cnt;
}