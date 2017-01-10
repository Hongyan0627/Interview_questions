//  LeetCode
//
//  Created by Hongyan on 01/09/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if(!head || !head->next) return head;
		
		ListNode dummy(0);
		
		ListNode* curr = head;

		while(curr) {
			ListNode* prev = &dummy;
			while(prev->next && prev->next->val <= curr->val) {
				prev = prev->next;
			}
			ListNode* tmp = curr->next;
			curr->next = prev->next;
			prev->next = curr;
			curr = tmp;
		}
		return dummy.next;
	}
}