// Leetcode 247 Delete Node in a linked list

#ifndef deleteNodeInList_h
#define deleteNodeInList_h

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* tmp = node->next;
        node->next = tmp->next;
        delete tmp;    
    }
};

#endif