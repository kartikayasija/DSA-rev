/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //calculate difference b/w size and shift the greater one
        int count1=0,count2=0;
        ListNode *temp1 = headA, *temp2 = headB;
        while(temp1) {
            count1++;
            temp1 = temp1->next;
        }
        while(temp2) {
            count2++;
            temp2 = temp2->next;
        }
        int diff = abs(count1-count2);
        for(int i = 0; i<diff; i++) {
            count1>count2 ? headA=headA->next : headB=headB->next;
        }
        /**************************************************************/

        //now compare
        while(headA and headB) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }


        return nullptr;
    }
};