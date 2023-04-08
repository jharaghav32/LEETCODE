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
    // we call dfs for starting node and  create a newnode of that node 
    // and push the node in hashmap so that we can count it as cloned map so next
    // time we don't again create it now we traverse the neighbors of node every node
    // we found in the neighbours if it is already cloned it mean we already traversed
    // it so we directly include it in node neighbors while if it is not cloned
    // call for dfs of that node after traversing all the neighbors simply made 
    // the created neighbors vector equal to node neighbors and return node.
    Node* dfs(Node*node,unordered_map<Node*,Node*>&ump){
        vector<Node*>neighbor;
        Node* newnode = new Node(node->val);
        ump[node]=newnode;
        for(auto i:node->neighbors){
            if(ump.find(i)!=ump.end())
                neighbor.push_back(ump[i]);
            else
            neighbor.push_back(dfs(i,ump));
        }
        newnode->neighbors=neighbor;
        return newnode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>ump;
        if(node==NULL)return NULL;
        return dfs(node,ump);
    }
};