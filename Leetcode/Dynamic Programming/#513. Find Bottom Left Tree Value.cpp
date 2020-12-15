/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int treeDepth(TreeNode* root){
        if(!root) return 0;
        return 1+max(treeDepth(root->left),treeDepth(root->right));
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int depth = treeDepth(root);
        queue<TreeNode*>Q;
        Q.push(root);
        
        int cnt=0;
        while(!Q.empty()){
              if(++cnt==depth) return Q.front()->val; 
            int size = Q.size();
            for(int i=0; i<size; i++){
                auto cur = Q.front(); Q.pop();
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
        }

        return 0;
        
    }
};