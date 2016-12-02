//Leetcode 141 Linked List Cycle

#ifndef linkedlistcycle_h
#define linkedlistcycle_h

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
    bool hasCycle(ListNode *head) {
    	if(!head || !head->next) return false;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        	if(slow == fast) {
        		return true;
        	}
        }
        return false;
    }
};

#endif