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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!(head and head->next)){
            return head;
        }

        int Size = size(head);

        /*
            if k = 4, then we have to rotate 4%3 -> 1 time
            so condition will be k % Size
        */
        for(int i=0; i < (k % Size); i++){

            ListNode *temp = head;

            //take node to last-second
            while(temp->next->next) {
                temp = temp->next;
            }


            //attach last node to head, and last-sec to null
            ListNode *tail = temp->next;
            temp->next = NULL;
            tail->next = head;
            head = tail;
        }
        

        return head;
    }

    int size(ListNode *head) {
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }

        return count;
    }
};