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
	// you can modify the input list
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* prev1 = NULL;
		ListNode* prev2 = NULL;

		while(l1) {
			ListNode* tmp = l1->next;
			l1->next = prev1;
			prev1 = l1;
			l1 = tmp;
		}

		while(l2) {
			ListNode* tmp = l2->next;
			l2->next = prev2;
			prev2 = l2;
			l2 = tmp;
		}

		l1 = prev1;
		l2 = prev2;

		int carry = 0;
		ListNode dummy(0);
		ListNode* p = &dummy;

		while(l1 || l2) {
			int tmp = carry;
			if(l1) {
				tmp += l1->val;
				l1 = l1->next;
			}

			if(l2) {
				tmp += l2->val;
				l2 = l2->next;
			}

			carry = tmp / 10;
			p->next = new ListNode(tmp % 10);
			p = p->next;
		}
		if(carry) {
			p->next = new ListNode(carry);
		}

		ListNode* prev = NULL;
		p = dummy.next;

		while(p) {
			ListNode* tmp = p->next;
			p->next = prev;
			prev = p;
			p = tmp;
		}

		return prev;
	}

	// don't modify the input list
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> list1, list2;
		while(l1) {
			list1.push(l1->val);
			l1 = l1->next;
		}
		while(l2) {
			list2.push(l2->val);
			l2 = l2->next;
		}

		int carry = 0;
		ListNode* prev = NULL;
		ListNode* p;
		while(!list1.empty() || !list2.empty()) {
			int sum = carry;
			if(!list1.empty()) {
				sum += list1.top();
				list1.pop();
			}
			if(!list2.empty()) {
				sum += list2.top();
				list2.pop();
			}
			carry = sum / 10;
			p = new ListNode(sum % 10);
			p->next = prev;
			prev = p;
		}
		if(carry) {
			p = new ListNode(carry);
			p->next = prev;
			prev = p;
		}
		return prev;
	}
}