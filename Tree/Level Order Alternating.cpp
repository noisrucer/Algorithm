/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    deque<Tree*>dq;
    dq.push_front(root);
    int level = 0;
    vector<int>res;

    while(!dq.empty()){ 
        int n = dq.size();
        for(int i=0; i<n; i++){
           if(level%2==0){
               auto cur = dq.front(); dq.pop_front();
               res.push_back(cur->val);
               if(cur->left) dq.push_back(cur->left); 
               if(cur->right) dq.push_back(cur->right); 
           }else{
               auto cur = dq.back(); dq.pop_back();
               res.push_back(cur->val);
               if(cur->right) dq.push_front(cur->right); 
               if(cur->left) dq.push_front(cur->left); 
           }
        }
        level++;
    }
    return res;
}
