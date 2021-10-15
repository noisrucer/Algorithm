/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node, int k) {
    LLNode* head = node;
    int n = 0;
    while(node){
        node=node->next;
        n++;
    }
    k = min(k,n-1-k);

    LLNode* slow = head, *fast = head;

    for(int i=0; i<k; i++) slow = slow->next;
    for(int i=0; i<n-1-k; i++) fast = fast->next;

    int temp = slow->val;
    slow->val = fast->val;
    fast->val = temp;

    return head;

}