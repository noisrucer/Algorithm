bool solve(Tree* root) {
    if(!root) return true;
    queue<Tree*>Q;
    Q.push(root);
    int n;
    bool flag;
    
    while(!Q.empty()){
        n = Q.size();
        for(int i=0; i<n; i++){
            auto cur = Q.front(); Q.pop();

            if(cur->left){
                if(flag) return false;
                Q.push(cur->left);
            }
            else flag = true;

            if(cur->right){
                if(flag) return false;
                Q.push(cur->right);
            }
            else flag = true;
        }
    }

    return true;
}