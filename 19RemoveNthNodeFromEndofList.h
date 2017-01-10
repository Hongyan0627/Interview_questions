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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(!head || n == 0) return head;
		ListNode* p1 = head;
		ListNode* p2 = head;
		for(int i = 0; i < n; i++) {
			p2 = p2->next;
		}

		ListNode dummy(0);
		dummy.next = head;

		ListNode* prev = &dummy;

		while(p2) {
			p1 = p1->next;
			p2 = p2->next;
			prev = prev->next;
		}

	    prev->next = p1->next;
	    delete p1;
	    return dummy.next;
	}
}