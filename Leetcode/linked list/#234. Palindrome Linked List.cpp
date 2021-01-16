ㅁclass Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow = reverse(slow->next);
        while(slow){
            if(slow->val != head->val) return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* p = NULL, *c = head, *n;
        while(c){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
};