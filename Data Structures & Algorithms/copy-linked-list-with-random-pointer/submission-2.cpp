class Solution {
public:
    Node* copyRandomList(Node* head){
        unordered_map<Node *, Node *> umap;

        Node *curr = head;
        while(curr != nullptr){
            umap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr != nullptr){
            umap[curr]->next = umap[curr->next];
            umap[curr]->random = umap[curr->random];
            curr = curr->next;
        }

        return umap[head];
    }
};
