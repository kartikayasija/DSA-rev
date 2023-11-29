class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return f(head, n);
    }
    ListNode* f(ListNode* head, int &n) {
        if (!head) {
            return NULL;
        }

        ListNode* nextNode = f(head->next, n);

        n--;

        if(n==0) {
            return head->next;
        }

        head->next = nextNode;

        return head;
    }
};