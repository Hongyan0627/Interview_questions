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
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* p = head;
		while(p) {
			ListNode* tmp = p->next;
			p->next = prev;
			prev = p;
			p = tmp;
		}
		return prev;
	}
}