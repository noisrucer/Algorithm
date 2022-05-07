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
    vector<int>res;
    int maxFreq = 0, curFreq = 0, cursor = INT_MIN;
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(cursor == root->val) curFreq++;
        else curFreq = 1;
        
        if(curFreq > maxFreq){
            res.clear();
            maxFreq = curFreq;
            res.push_back(root->val);
        }
        else if(curFreq == maxFreq){
            res.push_back(root->val);
        }
        
        cursor = root->val;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};