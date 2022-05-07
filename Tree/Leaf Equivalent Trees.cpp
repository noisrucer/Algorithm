/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int>order;
int idx;
int res;
void help(Tree* root){
    if(!root) return;
    if(!root->left && !root->right){
        if(res != -1){
            if(order[idx++] != root->val) res = false;
        }else order.push_back(root->val);
        return;
    }
    help(root->left);
    help(root->right);
}

bool solve(Tree* root1, Tree* root2) {
    order.clear();
    idx = 0;
    res = -1;
    help(root1);
    res = true;
    help(root2);
    return res;

}