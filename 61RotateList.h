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
	ListNode* rotateRight(ListNode* head, int k) {
		if(!head || !head->next) return head;
		ListNode* p = head;
		int n = 1;
		while(p->next) {
			p = p->next;
			n++;
		}
		k = k % n;
		p->next = head;
		for(int i = 0; i < (n - k); i++) {
			p = p->next;
		}
		ListNode* new_head = p->next;
		p->next = NULL;
		return new_head;
	}
}