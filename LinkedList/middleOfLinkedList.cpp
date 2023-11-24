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
    ListNode* middleNode(ListNode* head) {
        ListNode *slowPointer = head, *fastPointer = head;

        while(fastPointer and fastPointer->next){
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;
        }

        return slowPointer;
    }
};

/*
    https://www.youtube.com/watch?v=A2_ldqM4QcY&ab_channel=NeetCodeIO
    fast move 2 steps, slow move one step
    fast speed is double than slow
    when fast will reach final, slow will be at half the way
    that's what we needed
*/