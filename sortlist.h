// Leetcode 148 Sort List

#ifndef sortlist_h
#define sortlist_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	ListNode *merge(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode *head = &dummy;
		while(l1 && l2) {
			if(l1->val < l2->val) {
				head->next = l1;
				l1 = l1->next;
			} else {
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		if(l1) {
			head->next = l1;
		}

		if(l2) {
			head->next = l2;
		}

		return dummy.next;
	}
public:
    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next) return head;
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next) {
        	fast = fast->next->next;
        	slow = slow->next;
        }

        fast = slow->next;
        slow->next = NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(fast);
        return merge(l1, l2);
    }
};

#endif