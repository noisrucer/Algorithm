//Track minimum as proceeding inorder-traversal (faster)
class Solution {
    public:
    int minDiff = INT_MAX;
    void inorder(TreeNode* root, int &val){
        if(!root) return;
        inorder(root->left,val);
        minDiff=min(minDiff,abs(root->val - val));
        val = root->val;
        inorder(root->right,val);
    }
    

    int getMinimumDifference(TreeNode* root) {
        int val = INT_MAX;
        inorder(root,val);
        return minDiff;
    }
};

//Another way is to store all the values in the vector
class Solution {
    public:
    vector<int> res;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    int minDiff(){
        int minVal=INT_MAX;
        for(int i=0; i<res.size()-1; i++){
            minVal = min(minVal,res[i+1]-res[i]);
        }
        return minVal;
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff();
    }
};
