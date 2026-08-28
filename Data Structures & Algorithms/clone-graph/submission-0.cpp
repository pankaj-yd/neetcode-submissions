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
        unordered_map<Node *, Node *> mapping;
        Node *curr = node;
        stack<Node *> s;
        while(curr != nullptr || !s.empty()){
            if( mapping.find(curr) == mapping.end()){
                Node *newNode = new Node(curr->val);
                mapping.insert({curr, newNode});

                for(Node *neighbor : curr->neighbors){
                    s.push(neighbor);
                }
            }
            if(!s.empty()){
                curr = s.top();
                s.pop();
            } else {
                curr = nullptr;
            }
        }

        for(auto it : mapping){
            Node *oldNode = it.first;
            Node *newNode = it.second;
            for(Node *neigh : oldNode->neighbors){
                newNode->neighbors.push_back(mapping[neigh]);
            }
        }

        return mapping[node];

    }
};
