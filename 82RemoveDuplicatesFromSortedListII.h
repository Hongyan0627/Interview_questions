//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode dummy(0);
		dummy.next = head;
		ListNode* prev = &dummy;
		ListNode* p = head;
		bool flag = false;
		while(p) {
			if(p->next && p->val == p->next->val) {
				flag = true;
				while(p->next && p->val == p->next->val) {
					ListNode* tmp = p->next;
					p->next = tmp->next;
					delete tmp;
				}
			}

			if(flag) {
				ListNode* tmp = p;
				p = p->next;
				prev->next = p;
				delete tmp;
				flag = false;
			} else {
				prev = p;
				p = p->next;
			}
		}
		return dummy.next;
	}
}