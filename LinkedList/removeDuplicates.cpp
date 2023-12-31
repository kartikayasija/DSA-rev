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
    ListNode* deleteDuplicates(ListNode* head) {
        //base
        if(head==NULL or head->next==NULL) {
            return head;
        }

        //right sub problem solved by recursion
        head->next = deleteDuplicates(head->next);

        //solved by me
        if(head->val == head->next->val) {
            head = head->next;
        }

        return head;

    }
};