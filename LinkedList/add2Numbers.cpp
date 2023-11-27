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
        ListNode *newHead = new ListNode();
        ListNode *temp = newHead;
        int carry = 0;

        while(l1 or l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            
            //first plus
            int value = v1 + v2 + carry;

            //find carry
            carry = value/10;


            //ans for this node will be value%10
            int onesPlace = value % 10;
            
            //add that to next node
            temp->next = new ListNode(onesPlace);

            //inc
            temp = temp->next;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }

        //if there is any carry at end, so create new node for it
        if (carry != 0) {
            temp->next = new ListNode(carry);
        }
        

        return newHead->next;
    }

};