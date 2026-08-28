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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            int val = sum%10;
            ListNode *newNode = new ListNode(val);
            if(curr != nullptr){
                curr->next = newNode;
                curr = newNode;
            }
            if(head == nullptr){
                head = newNode;
                curr = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *remList = nullptr;
        if(l1 != nullptr){
            remList = l1;
        } else{
            remList = l2;
        }
        while(remList != nullptr){
            int val = remList->val;
            int sum = val + carry;
            carry = sum/10;
            val = sum%10;
            ListNode *newNode = new ListNode(val);
            curr->next = newNode;
            curr = newNode;
            remList = remList->next;
        }

        if(carry > 0){
            ListNode *newNode = new ListNode(carry);
            curr->next = newNode;
            curr = newNode;
        }

        return head;
    }
};
