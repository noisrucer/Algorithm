/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*, Node*>mp;
       
        mp[node]=new Node(node->val);
        queue<Node*>Q;
        Q.push(node);
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(auto neighbor: cur->neighbors){
                if(!mp.count(neighbor)){
                mp[neighbor]=new Node(neighbor->val);
                Q.push(neighbor);
                }
                
                mp[cur]->neighbors.push_back(mp[neighbor]);
            }
        }
        
        return mp[node];
    }
};