class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = nullptr;
        ListNode *left = head;
        ListNode *right = head;

        int i = 0;
        while(i < n && right != NULL){
            right = right->next;
            i++;
        }

        if(i != n){
            return nullptr;
        }

        while(right != nullptr){
            prev = left;
            left = left->next;
            right = right->next;
        }

        if(prev == nullptr){
            head = head->next;
        } else {
            prev->next = left->next;
            left->next = nullptr;
        }

        return head;
    }
};
