class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHead = new ListNode(0), *rightHead = new ListNode(0);
        ListNode *left = leftHead, *right = rightHead;


        while(head) {
            if(head->val < x) {
                left->next = head;
                left = left->next;
            }
            else{
                right->next = head;
                right = right->next;
            }

            head = head->next;
        }

        left->next = rightHead -> next;

        //bcz we are not creating new node, we are attaching head
        right->next = NULL;

        return leftHead->next;
    }
};