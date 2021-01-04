/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* l1, LLNode* l2) {
    LLNode *temp = new LLNode();
    LLNode *head = temp;


    while(l1 || l2){
        LLNode* node = new LLNode();
        if(!l1){
            temp->next = l2;
            break;
        }
        if(!l2){
            temp->next = l1;
            break;
        }
        if(l1->val < l2->val){
            node->val = l1->val;
            l1=l1->next;
        }
        else if(l1->val > l2->val){
            node->val = l2->val;
            l2=l2->next;
        }
        else{
            node->val = l1->val;
            l1=l1->next;
            l2=l2->next;
        }
        temp->next = node;
        temp=temp->next;
    }
    return head->next;
}