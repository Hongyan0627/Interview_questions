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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(0);
		dummy.next = head;
		ListNode* prev = &dummy;
		ListNode* p = head;
		while(p) {
			if(p->val == val) {
				prev->next = p->next;
				delete p;
				p = prev->next;
			} else {
				prev = p;
				p = p->next;
			}
		}
		return dummy.next;
	}
}