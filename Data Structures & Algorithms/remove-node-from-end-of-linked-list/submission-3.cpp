class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *right = head, *left = dummy;

        while(n){
            right = right->next;
            n--;
        }

        while(right != nullptr){
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return dummy->next;
    }
};
