//Leetcode 206 Reverse Linked List

#ifndef reverselinkedlist_h
#define reverselinkedlist_h

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
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = nullptr;
        while(head) {
        	ListNode *p = new ListNode(head->val);
        	p->next = new_head;
        	new_head = p;
        	head = head->next;
        }
        return new_head;
    }
};

#endif