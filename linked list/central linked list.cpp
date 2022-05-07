//Find the center of linked list
// if size==odd -> center
// if size==even -> second one of the two centers 

//slow & two pointers
int solve(LLNode* node) {
   LLNode *slow = node, *fast = node;
   while(fast!=NULL&&fast->next!=NULL){
       slow=slow->next;
       fast=fast->next->next;
   }
   return slow->val;
}