class Solution {
public:
    Node* copyRandomList(Node* head) {
        int i = 0;
        unordered_map<Node *, int> oldMap;
        unordered_map<int, Node *> newMap;

        Node *oldHead = head;
        Node *newHead = nullptr;
        Node *newCurr = nullptr;
        
        while(oldHead != nullptr){
            oldMap.insert({oldHead, i});

            Node *newNode = new Node(oldHead->val);

            if(newHead == nullptr){
                newHead = newNode;
                newCurr = newNode;
                newMap.insert({i, newNode});
                i++;
                oldHead = oldHead->next;
                continue;
            }

            newCurr->next = newNode;
            newCurr = newNode;
            newMap.insert({i, newNode});
            i++;
            oldHead = oldHead->next;
        }


        oldHead = head;
        Node *newHeadCopy = newHead;
        while(oldHead != NULL){
            if(oldHead->random != NULL){
                newHeadCopy->random = newMap[ oldMap[oldHead->random] ];
            } else {
                newHeadCopy->random = nullptr;
            }
            oldHead = oldHead->next;
            newHeadCopy = newHeadCopy->next;
        }

        return newHead;

    }
};
