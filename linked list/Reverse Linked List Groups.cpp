
LLNode* solve(LLNode* node, int k) {
     LLNode *p=NULL, *c=node, *n;
    int cnt=0;
    while(cnt<k && c){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        cnt++;
    }
    if(c) node->next = solve(c,k);
    return p;
}