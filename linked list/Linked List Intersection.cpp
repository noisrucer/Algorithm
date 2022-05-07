LLNode* solve(LLNode* l1, LLNode* l2) {
    LLNode *p1 = l1, *p2 = l2;
    LLNode* head = new LLNode(1);
    LLNode* dummy = head;

    while(p1 && p2){
        if(p1->val == p2->val){
            dummy->next = new LLNode(p1->val);
            dummy = dummy->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->val > p2->val){
            p2 = p2->next;
        }
        else p1 = p1->next;
    }

    return head->next;
}