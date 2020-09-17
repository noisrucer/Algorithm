
class Solution {
public:
  vector<int>vec;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        for(int i=0, j=vec.size()-1;i<j;){
            if(vec[i]+vec[j]==k)return true;
            (vec[i]+vec[j]<k)?i++:j--;
        }
        return false;
    }
    
};