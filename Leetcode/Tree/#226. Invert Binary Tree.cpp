
//Using Stack
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*>st;
        st.push(root);
        
        while(!st.empty()){
            auto cur = st.top(); st.pop();
            if(cur){
                st.push(cur->left);
                st.push(cur->right);
                swap(cur->left,cur->right);
            }
        }
        return root;
    }
};


//recursion
class Solution {
public:
    
    TreeNode* helper(TreeNode* root){
       if(!root) return NULL;
        TreeNode* left = root->left;
        root->left = helper(root->right);
        root->right = helper(left);
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return helper(root);
    }
};
