class Solution {
public:
    string dfs(TreeNode* root){
        if(!root) return "";
        string l = dfs(root->left);
        string r = dfs(root->right);
        
        string res = to_string(root->val);
        
        if(l == "" && r == "") return res;
        res += "(" + l +")";
        if(r != "") res += "(" + r + ")";
        
        return res;
    }
    
    string tree2str(TreeNode* root) {
        return dfs(root);
    }
};