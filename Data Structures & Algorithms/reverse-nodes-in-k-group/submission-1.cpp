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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *ansList = nullptr;
        ListNode *ansListEnd = nullptr;
        
        ListNode *curr = head;
        while(curr != nullptr){
            ListNode *dummy = nullptr;
            ListNode *dummyEnd = nullptr;

            int count = 0;
            while(curr != nullptr && count < k){
                ListNode *next = curr->next;
                curr->next = dummy;
                dummy = curr;
                curr = next;

                if(dummyEnd == nullptr){
                    dummyEnd = dummy;
                }
                count++;
            }

            if(count == k){
                if(ansList == nullptr){
                    ansList = dummy;
                } else {
                    ansListEnd->next = dummy;
                }
                ansListEnd = dummyEnd;
                if(ansListEnd != nullptr){
                    delete ansListEnd->next;
                    ansListEnd->next = nullptr;
                }
            } else {
                curr = dummy->next;
                dummy->next = nullptr;
                
                while(curr != nullptr){
                    ListNode *tmp = curr->next;
                    curr->next = dummy;
                    dummy = curr;
                    curr = tmp;
                }
                ansListEnd->next = dummy;
            }
        }

        return ansList;
    }
};
