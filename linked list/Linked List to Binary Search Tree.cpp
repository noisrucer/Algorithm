/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
Tree* BST(LLNode* head){
    if(!head) return NULL;
    if(!head->next) return new Tree(head->val);
    
    LLNode *left=head, *root = head, *fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        left = root;
        root = root->next; 
    }
    left->next = NULL;

    Tree* rootNode = new Tree(root->val);
    rootNode->left = BST(head);
    rootNode->right = BST(root->next);
    return rootNode; 
}
Tree* solve(LLNode* node) {
    return BST(node);
}