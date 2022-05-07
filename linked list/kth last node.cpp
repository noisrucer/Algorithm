//Method1: two pointers
int solve(LLNode* head, int k) {
    //two pointers
    LLNode *slow = head, *fast = head;
    for(int i=0; i<k; i++) fast=fast->next;
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    return slow->val;
}

//Method2: move size-k-1 

int solve(LLNode* head, int k) {
    //size-k-1
    int size=0;
    LLNode*temp = head;
    while(temp){
        temp=temp->next;
        size++;
    }
    for(int i=0; i<size-k-1; i++) head=head->next;
    return head->val;
}