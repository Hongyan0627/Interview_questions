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
	ListNode* merge(ListNode* l1, ListNode* l2) {
		if(!l1) return l2;
		if(!l2) return l1;
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
		} else if (l2) {
			p->next = l2;
		}
		return dummy.next;
	}
	ListNode* sortList(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		fast = slow->next;
		slow->next = NULL;

		ListNode* head1 = sortList(head);
		ListNode* head2 = sortList(fast);
		return merge(head1,head2);
	}
};