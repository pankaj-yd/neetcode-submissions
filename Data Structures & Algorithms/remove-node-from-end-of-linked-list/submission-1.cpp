class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        
        int count = 0;
        while(slow != NULL){
            slow = slow->next;
            count++;
        }

        cout << count;
        int frontIdx = count - n;
        ListNode *itr = head;
        if(frontIdx == 0){
            itr = itr->next;
            head->next = nullptr;
            head = itr;
            return head;
        }

        itr = head;
        int i = 1;
        while( i < frontIdx){
            itr = itr->next;
            i++;
        }

        ListNode *nextPtr = itr->next;
        if(nextPtr != NULL){
            nextPtr = nextPtr->next;
        }
        itr->next = nextPtr;


        return head;
    }
};
