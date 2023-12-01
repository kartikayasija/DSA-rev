/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;

        Node *curr = head;

        while(curr) {
            //create a new node
            Node *newNode = new Node(curr->val);

            //save it to map
            mp[curr] = newNode;

            //inc curr
            curr = curr->next;
        } 

        curr = head;

        while(curr) {

            //any change is newNode will be the change in node stored in map
            Node *newNode = mp[curr];
            newNode->next = mp[curr->next];
            newNode->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};