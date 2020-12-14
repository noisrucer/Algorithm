//DFS
class Solution {
public:
    void help(Node* root, Node* n, int LR){
        if(!root) return;
        
        if(LR==1) root->next=n->right;
        else if(LR==2){
           if(n->next) root->next=n->next->left;
        }
        
        help(root->left,root,1);
        help(root->right,root,2);
    }
    
    Node* connect(Node* root) {
        help(root,NULL,3);
        return root;
    }
};

//BFS
class Solution {
public:
    
    Node* connect(Node* root) {
    if(!root) return root;
       queue<Node*>Q;
        Q.push(root);
        
        while(!Q.empty()){
            int n = Q.size();
            int cnt=0;
            for(int i=0; i<n; i++){
                Node* cur = Q.front(); Q.pop(); 
                if(i!=n-1) cur->next=Q.front(); cnt++;
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
        }
        
        return root;
    }
};