class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* left = head;
        return isPalindromeRecursive(left, head);
    }

    bool isPalindromeRecursive(ListNode*& left, ListNode* right) {
        if (right == nullptr) {
            return true;
        }

        bool rec_ans = isPalindromeRecursive(left, right->next);
        if (!rec_ans) {
            return false;
        }

        if (left->val == right->val) {
            left = left->next;
            return true;
        }

        return false;
    }
};