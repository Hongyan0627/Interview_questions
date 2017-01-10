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
	bool isPalindrome(ListNode* head) {
		if(!head || !head->next) return true;
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		fast = slow->next;
		slow->next = NULL;
		ListNode* prev = NULL;
		while(fast) {
			ListNode* tmp = fast->next;
			fast->next = prev;
			prev = fast;
			fast = tmp;
		}

		ListNode* head1 = head;
		ListNode* head2 = prev;

		while(head2 && head1) {
			if(head1->val != head2->val) return false;
			head1 = head1->next;
			head2 = head2->next;
		}

		head2 = prev;
		prev = NULL;
		while(head2) {
			ListNode* tmp = head2->next;
			head2->next = prev;
			prev = head2;
			head2 = tmp;
		}

		slow->next = prev;
		return true;
	}
}