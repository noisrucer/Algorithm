//No creation of new tre -> track t1

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return NULL;
        if(!t1 || !t2) {
            return t1 ? t1 : t2;
        }
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
        
    }
    
    
};
// Create new tree =
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1&&!t2) return NULL;
        if(!t1 && t2) return t2;
        if(t1 && !t2) return t1;
        TreeNode* node = new TreeNode();
        node->val = t1->val + t2->val;
        node->left = mergeTrees(t1->left,t2->left);
        node->right = mergeTrees(t1->right,t2->right);
        return node;
        
    }
    
    
};