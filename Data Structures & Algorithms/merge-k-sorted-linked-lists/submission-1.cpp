
class Solution {
public:
    void printList(ListNode *head){
        ListNode *curr = head;
        while(curr != nullptr){
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << "\n";
    }

    ListNode* merge(ListNode *l, ListNode *r){
        cout << "merging" << endl;
        printList(l);
        printList(r);

        ListNode *head = nullptr;
        ListNode *curr = nullptr;

        while(l != nullptr && r != nullptr){
            ListNode *minNode = nullptr;
            if(l->val < r->val){
                minNode = l;
                l = l->next;
            } else {
                minNode = r;
                r = r->next;
            }

            if(head == nullptr){
                head = minNode;
                curr = minNode;
                continue;
            }
            curr->next = minNode;
            curr = minNode;
        }

        if(l == nullptr){
            curr->next = r;
        } else{
            curr->next = l;
        }

        printList(head);
        return head;
    }

    ListNode *mergeSort(vector<ListNode*>& lists, int l, int r){
        if(l == r){
            return lists[l];
        }
        int m = l + (r - l)/2;
        ListNode *left = mergeSort(lists, l, m);
        ListNode *right = mergeSort(lists, m+1, r);

        ListNode *ans = merge(left, right);

        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return nullptr;
        return mergeSort(lists, 0, k-1);
    }
};
