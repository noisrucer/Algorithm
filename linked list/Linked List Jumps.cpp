/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

LLNode* solve(LLNode* node) {
    LLNode* head = node;
    LLNode* fast = node;
    while(node){
        for(int i=0; i<node->val; i++){
            if(!fast) break;
            fast = fast->next;
        }
        node->next = fast;
        node=node->next;
    }
    
    return head;

}