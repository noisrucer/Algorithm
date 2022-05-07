/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* l1, LLNode* l2) {
    LLNode* head = new LLNode(0);
    LLNode* res = head;
   while(l1 && l2){
       if(l1->val == l2->val){
           head->next = l1;
           l1 = l1->next;
           l2 = l2->next;
       }
       else if(l1->val < l2->val){
           head->next = l1;
           l1 = l1->next;
       }
       else{
           head->next = l2;
           l2 = l2->next;
       }
       head = head->next;
   }

   if(l1) head->next = l1;
   if(l2) head->next = l2;
   return res->next;
}