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
    int size = 0;
    ListNode* left;
    int pairSum(ListNode* head) {
        left = head;
        size = calcSize(head);
        return f(head, 0);
    }

    int f(ListNode* head, int floor) {

        if(!head) return INT_MIN;

        int maxi = f(head->next, floor+1);

        if(floor < size/2) {
            return maxi;
        }
        int sum = left->val + head->val;

        left = left->next;
        
        return max(maxi, sum);
    }

    int calcSize(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head=head->next;
        }

        return count;
    }
};