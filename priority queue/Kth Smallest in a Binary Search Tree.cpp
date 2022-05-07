/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

//priority queue
void dfs(Tree* root, int k, priority_queue<int> &pq){
    if(!root) return;
    pq.push(root->val);
    if(pq.size() > k) pq.pop();
    dfs(root->left,k,pq);
    dfs(root->right,k,pq);
}
int solve(Tree* root, int k) {
    priority_queue<int>pq;
    dfs(root,k+1,pq);
    return pq.top();
}

//inorder traversal
int res;
void dfs(Tree* root, int k, int &cnt){
   if(!root) return;
   dfs(root->left,k,cnt);
   if(cnt++ == k) res = root->val;
   dfs(root->right,k,cnt);
}
int solve(Tree* root, int k) {
    res = 0;
    int cnt=0;
    dfs(root,k,cnt);
    return res;
}