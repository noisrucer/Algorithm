class Solution {
public:
    
    void recursion(TreeNode* root, int &sum, int L, int R){
        if(!root) return;
        if(root->val>=L && root->val<=R) sum+=root->val;
        if(root->val>L && root->val<R){
            recursion(root->left,sum,L,R);
            recursion(root->right,sum,L,R);
        }
        if(root->val<=L) recursion(root->right,sum,L,R);
        if(root->val>=R) recursion(root->left,sum,L,R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum=0;
        recursion(root,sum,L,R);
        return sum;
    }
    
};