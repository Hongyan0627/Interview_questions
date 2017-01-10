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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode* p = &dummy;
		while(l1 && l2) {
			if(l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if(l1) {
			p->next = l1;
		} else if(l2) {
			p->next = l2;
		}
		return dummy.next;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if(n == 0) return NULL;
		if(n == 1) return lists[0];
		while(n > 1) {
			int k = (n + 1)/2;
			for(int i = 0; i < n/2; i++) {
				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			}
			n = k;
		}
		return lists[0];
	}
};