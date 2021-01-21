/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node) {
    LLNode* slow=node, *fast = node, *head = node;
    LLNode *p=NULL, *c=node, *n;
    while(fast && fast->next){
        fast = fast->next->next;
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        slow = c;
    }
    head = slow;
    if(fast) slow = slow->next;
    while(slow){
        slow->val += p->val;
        slow=slow->next; 
        p=p->next;
    }
    return head;
}
