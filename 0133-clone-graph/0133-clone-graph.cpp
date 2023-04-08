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
    Node* clone(Node* node,unordered_map<Node*,Node*>& mp){
        if(node==NULL){
            return NULL;
        }
        Node* newNode = new Node(node->val);
        mp.insert({node,newNode});
        for(auto i: node->neighbors){
            if(mp.find(i)==mp.end()){
                Node* curr = clone(i,mp);
                if(curr!=NULL){
                    newNode->neighbors.push_back(curr);
                }
            }
            else{
                newNode->neighbors.push_back(mp.find(i)->second);
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> mp;
        return clone(node,mp);
    }
};