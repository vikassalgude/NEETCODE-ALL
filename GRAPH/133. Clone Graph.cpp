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
    
    unordered_map<Node*,Node*>mp;
    // void dfs(Node*node,Node* clonednode){
    //     for(Node* n:node->neighbors){
    //         if(mp.find(n)==mp.end()){
    //             Node* clone=new Node(n->val);
    //             mp[n]=clone;
    //             clonednode->neighbors.push_back(clone);
    //              dfs(n,clone);
    //         }else{
    //              clonednode->neighbors.push_back(mp[n]);
    //         }
    //     }
    // }
    void bfs(queue<Node*>&q){
        while(!q.empty()){
            Node* node=q.front();
            Node* clonednode=mp[node];
            q.pop();
            for(Node* n:node->neighbors){
                if(mp.find(n)==mp.end()){
                 Node* clone=new Node(n->val);
                 mp[n]=clone;
                 clonednode->neighbors.push_back(clone);
                 q.push(n);
                }
                else{
                  clonednode->neighbors.push_back(mp[n]);
                }
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        mp.clear();
        //cloned gived node
        Node* clonednode=new Node(node->val);
        //cloned its neighbour and recursively their neighbour
        // but if a node reappears, then we need to access clone node
        // so store in a map  or vector
        // unordered_map<Node*,Node*>mp;
        mp[node]=clonednode;
      //  dfs(node,clonednode);
        
        queue<Node*>q;
        q.push(clonednode);
        bfs(q);
        return clonednode;
    }
};
