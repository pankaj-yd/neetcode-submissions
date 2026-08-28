class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }

        unordered_map<Node *, Node *> oldToNew;

        Node *itr = head;

        while(itr != nullptr){
            Node *newNode = new Node(itr->val);
            oldToNew.insert({itr, newNode});
            itr = itr->next;
        }

        itr = head;
        while(itr != nullptr){
            Node *newNode = oldToNew[itr];
            if(itr->next){
                newNode->next = oldToNew[itr->next];
            }
            if(itr->random){
                newNode->random = oldToNew[itr->random];
            }

            itr = itr->next;
        }

        return oldToNew[head];
    }
};
