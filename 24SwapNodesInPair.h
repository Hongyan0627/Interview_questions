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
	ListNode* swapPairs(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode dummy(0);
		dummy.next = head;

		ListNode* prev = &dummy;
		ListNode* p1 = head;
		ListNode* p2 = head->next;

		while(true) {
			ListNode* tmp = p2->next;

			p1->next = tmp;
			p2->next = p1;
			prev->next = p2;

			prev = p1;
			p1 = tmp;
			if(!p1 || !p1->next) break;
			else p2 = p1->next;
		}
		return dummy.next;
	}
}