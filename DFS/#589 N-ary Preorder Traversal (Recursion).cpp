
class Solution {
public:
    vector<int>res;
    void pre(Node* root){
        if(!root) return;
        res.push_back(root->val);
        for(int i=0; i<root->children.size(); i++){
            pre(root->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        pre(root);
        return res;
    }
};