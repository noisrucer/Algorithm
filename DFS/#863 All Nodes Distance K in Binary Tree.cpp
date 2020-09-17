
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>mp;
    
    void pair(TreeNode* root, TreeNode* parent){
        if(!root) return;
        mp[root]=parent;
        pair(root->left,root);
        pair(root->right,root);
    }
    
    vector<int> bfs(TreeNode* target, int K){
        unordered_set<TreeNode*> visited;
        queue<TreeNode*>Q;
        vector<int>res; 
        Q.push(target); visited.insert(target);
        int cnt=0;
        
        while(!Q.empty()){
            if(cnt==K){
                while(!Q.empty()){
                    res.push_back(Q.front()->val);
                    Q.pop();
                }
                return res;
            }
            int size = Q.size();
            for(int i=0; i<size; i++){
            auto cur = Q.front(); Q.pop();
          
            if(cur->left && !visited.count(cur->left)){
                Q.push(cur->left);
                visited.insert(cur->left);
            }
                if(cur->right &&!visited.count(cur->right)){
                    Q.push(cur->right);
                    visited.insert(cur->right);
                }
                
            if(mp.count(cur)&&mp[cur]!=NULL && !visited.count(mp[cur])){
                Q.push(mp[cur]);
                visited.insert(mp[cur]);
             }
            }
            cnt++;

        }
        return res;
    }
    
    vector<int>ans;
    unordered_set<TreeNode*> vis;
    void dfs(TreeNode* target, int K){
        if(!target) return;
        if(vis.count(target)) return; 
        vis.insert(target);
        if(K==0){
            ans.push_back(target->val);
            return;
        }
        dfs(target->left,K-1);
        dfs(target->right,K-1);
        if(mp[target]!=NULL && mp.count(target)){
            dfs(mp[target],K-1);
        }
        
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        pair(root,nullptr);
        dfs(target,K);
        return ans;
        //return bfs(target,K);
    }
};