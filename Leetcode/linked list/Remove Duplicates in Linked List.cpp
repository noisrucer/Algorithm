LLNode* solve(LLNode* node) {
    if(!node) return NULL;
    unordered_set<int>st;
    LLNode* cur = node, *next = node;
    st.insert(cur->val);

    while(cur && cur->next){
        next = cur->next;
        if(st.count(next->val)) cur->next = next->next;
        else{
            cur = cur->next;
            st.insert(next->val);
        }
    }

    return node;
    
}