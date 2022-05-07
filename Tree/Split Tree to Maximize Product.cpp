/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int res; 
int total;

int getTotal(Tree *root){
    if(!root) return 0;
    return root->val + getTotal(root->left) + getTotal(root->right);
}

int sum(Tree* root){
    if(!root) return 0;
    int left_sum = sum(root->left);
    int right_sum = sum(root->right);
    res = max(res, (total-left_sum)*left_sum);
    res = max(res, (total-right_sum)*right_sum);

    return root->val + left_sum + right_sum;
}

int solve(Tree* root) {
    res = INT_MIN;
    total = getTotal(root);
    sum(root);
    return res;
}