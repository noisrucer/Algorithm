
class Solution {
public:
    int sum=0;
   void recursion(TreeNode* root, int L, int R){
       if(!root)return;
       recursion(root->left,L,R);
       if(root->val>=L && root->val<=R)sum+=root->val;
       recursion(root->right,L,R);
   }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        recursion(root,L,R);
        return sum;
    }
    
};