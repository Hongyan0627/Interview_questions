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
	void reorderList(ListNode* head) {
		if(!head || !head->next) return;

		ListNode* slow = head;
		ListNode* fast = head;
		
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		
		fast = slow->next;
		slow->next = NULL;
		
		ListNode* p2 = NULL;
		while(fast) {
			ListNode* tmp = fast->next;
			fast->next = p2;
			p2 = fast;
			fast = tmp;
		}

		ListNode* p1 = head;

		while(p2) {
			ListNode* tmp1 = p1->next;
			ListNode* tmp2 = p2->next;
			p1->next = p2;
			p2->next = tmp1;
			p1 = tmp1;
			p2 = tmp2;
		}
	}	
}