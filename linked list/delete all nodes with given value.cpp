/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node, int target) {
    if(!node) return NULL;
    if(node->val == target) return solve(node->next, target);
    node->next = solve(node->next, target);
    return node;
}


//Iterative 1
LLNode* solve(LLNode* node, int target) {
    LLNode *slow=node, *fast=node;
    while(slow){
        if(slow->val==target){
            slow=slow->next;
            node=node->next;
        }
        else{
            fast = slow->next;
            while(fast && fast->val==target) fast=fast->next;
            slow->next = fast;
            slow = fast;
        }
    }
    return node;
}

//Iterative 2

LLNode* solve(LLNode* node, int target) {
    LLNode *temp = node;
    while(temp){
        while(temp->next && temp->next->val == target)
            temp->next = temp->next->next;
        temp = temp->next;
    }
    return node->val==target?node->next:node;
}