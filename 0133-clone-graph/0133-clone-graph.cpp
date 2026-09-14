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
private:
    Node *dfs(Node *node,unordered_map<Node *,Node *>&mp){
        Node *newnode;
        if(!mp[node]){
            newnode=new Node (node->val);
            mp[node]=newnode;
        }
        else{
            newnode=mp[node];
        }
        for(auto it:node->neighbors){
            if(!mp[it]){
                dfs(it,mp);
            }
            newnode->neighbors.push_back(mp[it]);
        }
        return newnode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        Node *answer=new Node();
        unordered_map<Node *,Node *>mp;
        answer=dfs(node,mp);   

        return answer;
    }
};