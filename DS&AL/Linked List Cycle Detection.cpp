ListNode* ptr = head;
        while(ptr!=NULL){
         if(ptr->val==INT_MAX){
             return true;
         }
            ptr->val =INT_MAX;
            ptr=ptr->next;
        }
        return false;
    }