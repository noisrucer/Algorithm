/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

LLNode* solve(LLNode* l1, LLNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;

    bool flag = true;
    LLNode* head = new LLNode(0);
    LLNode* dummy = head;
    while(l1 && l2){
        if(flag){
            dummy->next = l1;
            l1 = l1->next;
            flag = false;
        }else{
            dummy->next = l2;
            l2 = l2->next;
            flag = true;
        }
        dummy = dummy->next;
    }
    if(!l1) dummy->next = l2;
    if(!l2) dummy->next = l1;

    return head->next;
    
}