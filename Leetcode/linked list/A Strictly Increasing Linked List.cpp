/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
bool solve(LLNode* head) {
    int prev = INT_MIN;
    while(head){
        if(head->val <= prev) return false;
        prev = head->val;
        head = head->next;
    }
    return true;
}