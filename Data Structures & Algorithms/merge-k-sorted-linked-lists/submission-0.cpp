class Solution {

public:
    bool operator () (ListNode *p, ListNode *q){
        return p->val > q->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }

    
        priority_queue<ListNode*, vector<ListNode*>, Solution> pq;

        for( auto element : lists){
            pq.push(element);
        }

        ListNode *head = nullptr;
        ListNode *curr = nullptr;

        while(!pq.empty()){
            ListNode *ptr = pq.top();
            pq.pop();
            if(head == nullptr){
                head = ptr;
                curr = ptr;
                if(ptr->next != nullptr){
                    pq.push(ptr->next);
                }
                continue;
            }

            if(ptr->next != nullptr){
                pq.push(ptr->next);
            }

            curr->next = ptr;
            ptr->next = nullptr;
            curr = ptr;
        }
        
        return head;
        
    }
};
