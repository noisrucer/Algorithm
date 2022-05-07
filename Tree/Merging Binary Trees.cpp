/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

Tree* dfs(Tree* n1, Tree* n2) {
    Tree* sub = new Tree();
    if (n1 && n2) sub->val = n1->val + n2->val;
    else if (n1 && !n2) return n1;
    else if (!n1 && n2) return n2;
    else return NULL;
    sub->left = dfs(n1->left, n2->left);
    sub->right = dfs(n1->right, n2->right);
    return sub;
}
Tree* solve(Tree* node0, Tree* node1) {
    return dfs(node0, node1);
}