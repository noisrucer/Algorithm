/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

//1st method
LLNode* solve(LLNode* node) {
    if(!node) return NULL;
    LLNode*slow = node, *fast = node->next;
    int cnt=1;
    while(fast){
        if(cnt++ & 1) swap(slow->val,fast->val);
        slow=slow->next;
        fast=fast->next;
    }
    return node;
}

//2nd method
LLNode* solve(LLNode* node) {
    if(!node) return NULL;
    LLNode*slow = node, *fast = node->next;
    while(fast){
        swap(slow->val,fast->val);
        if(fast->next){
            fast=fast->next->next;
            slow=slow->next->next;;
        }
        else break;
    }
    return node;
}