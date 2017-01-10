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
	ListNode* oddEvenList(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode* tmp = head->next;

		ListNode* p1 = head;
		ListNode* p2 = head->next;

		while(p2 && p2->next) {
			p1->next = p2->next;
			p1 = p1->next;
			p2->next = p1->next;
			p2 = p2->next;
		}

		p1->next = tmp;

		return head;
	}
	
}