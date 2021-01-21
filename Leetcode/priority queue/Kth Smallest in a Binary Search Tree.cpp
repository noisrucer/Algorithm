/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
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