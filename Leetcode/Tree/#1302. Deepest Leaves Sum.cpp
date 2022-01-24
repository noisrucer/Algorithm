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
    int deepestLevel = 0;
    int res = 0;
    
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(root->left == root->right){
            if(level == deepestLevel) res += root->val;
            else if(level > deepestLevel){
                res = root->val;
                deepestLevel = level;
            }
            return;
        }
        
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 0);
        return res;
        
    }
};