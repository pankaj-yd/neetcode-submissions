/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left = head;
        ListNode *right = head;
        while(n >= 0){
            if(right == nullptr){
                right = head->next;
                head->next = nullptr;
                return right;
            }
            right = right->next;
            n--;
        }


        while(right != nullptr){
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;

        return head;

    }
};
