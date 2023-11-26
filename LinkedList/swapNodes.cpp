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
    ListNode* left;
    ListNode* swapNodes(ListNode* head, int k) {
        left=head;
        return f(head, k);
    }

    ListNode* f(ListNode* head, int &k) {
        if(!head){
            return NULL;
        }
        ListNode* nextNode = f(head->next, k);
        k--;
        if(k==0) {
            swap(left->val, head->val);
        }
        left=left->next;

        return head;
    }

};