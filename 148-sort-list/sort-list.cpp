class Solution {
public:

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if(l1) temp->next = l1;
        if(l2) temp->next = l2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        // find mid
        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        // recursive sort
        ListNode* left = sortList(head);
        right = sortList(right);

        // merge
        return merge(left, right);
    }
};