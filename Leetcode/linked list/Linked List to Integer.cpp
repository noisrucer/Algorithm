/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode* node) {
    int res=0;
    while(node){
        res = res*2 + node->val;
        node = node->next;
    }
    return res;
}