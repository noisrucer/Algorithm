/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

//return if left subtree === right subtree

bool solve(Tree* root) {
    if(!root) return true;
    stack<Tree*>left, right;
    left.push(root->left);
    right.push(root->right);
    while(!left.empty() && !right.empty()){
        auto l = left.top(), r = right.top();
        left.pop(); right.pop();
        if(!l&&!r) continue;
        if((!l||!r) || (l->val!=r->val)) return false;
        left.push(l->left); right.push(r->right);
        left.push(l->right); right.push(r->left);
    }
    return left.size() == right.size();
}