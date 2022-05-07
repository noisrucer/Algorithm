//BFS
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

//DFS -> key point: if the current node is visited, don't perform dfs but just return previously determined Node*

class Solution {
public:
    
    Node* dfs(Node* node,unordered_map<Node*,Node*>&mp){
       if(!node) return nullptr;
        
        if(!mp.count(node)){ // <- this is the key point
            mp[node]=new Node(node->val);
         for(auto &neighbor: node->neighbors){
            mp[node]->neighbors.push_back(dfs(neighbor,mp));
            }
        }
        
        return mp[node];
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>mp;
        return dfs(node,mp);
    }
};








