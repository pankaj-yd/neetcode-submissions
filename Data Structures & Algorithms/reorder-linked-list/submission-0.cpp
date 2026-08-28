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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            } else {
                break;
            }
            slow = slow->next;
        }


        ListNode *reverseList = slow->next;
        
        slow->next = NULL;
        ListNode *prev = NULL;
        ListNode *curr = reverseList;

        

        while(reverseList != NULL && reverseList->next != NULL){
            reverseList = reverseList->next;
            curr->next = prev;
            prev = curr;
            curr = reverseList;
        }
        if(curr != NULL){
            curr->next = prev;
        }

        ListNode *printHead = head;
        while(printHead != NULL){
            cout << printHead->val << "->";
            printHead = printHead->next;
        }
        cout << "\n";
        printHead = reverseList;
        while(printHead != NULL){
            cout << printHead->val << "->";
            printHead = printHead->next;
        }

        ListNode *merge = head;
        ListNode *next = NULL;
        while(reverseList != NULL){
            next = merge->next;
            merge->next = reverseList;
            ListNode *reverseListNext = reverseList->next;
            reverseList->next = next;
            reverseList = reverseListNext;
            merge = next;
        }
        
    }
};
