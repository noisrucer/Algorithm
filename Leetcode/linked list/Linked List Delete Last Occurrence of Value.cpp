/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node, int target) {
    LLNode *temp = node, *targetNode = NULL, *sep = node;
    while(temp){
        if(temp->val == target) targetNode = temp;
        temp = temp->next;
    }
    if(!targetNode) return node;
    if(targetNode == node) return node->next;
    while(sep->next != targetNode) sep = sep->next;
    sep->next = targetNode->next;
    return node;
    
    
}