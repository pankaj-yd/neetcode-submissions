/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULLptr) {}
 *     ListNode(int x) : val(x), next(NULLptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = NULL;

        while (head != NULL) {
            curr = head;
            head = head-> next;
            if( prev != NULL){
                curr-> next = prev;
                prev = curr;
            } else {
                prev = curr;
                curr-> next = NULL;
            }
        }
        head = prev;
        return head;
    }
};
