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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		int carry = 0;
		ListNode* newHead = &dummy;
		while(l1 && l2) {
			int tmp = l1->val + l2->val + carry;
			carry = tmp / 10;
			newHead->next = new ListNode(tmp % 10);
			newHead = newHead->next;
			l1 = l1->next;
			l2 = l2->next;
		}

		while(l1) {
			int tmp = l1->val + carry;
			carry = tmp / 10;
			newHead->next = new ListNode(tmp % 10);
			newHead = newHead->next;
			l1 = l1->next;
		}

		while(l2) {
			int tmp = l2->val + carry;
			carry = tmp / 10;
			newHead->next = new ListNode(tmp % 10);
			newHead = newHead->next;
			l2 = l2->next;
		}

		if(carry) {
			newHead->next = new ListNode(carry);
		}

		return dummy.next;
	}
}