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

clas Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode* head = &dummy;
		while(l1 && l2) {
			if(l1->val < l2->val) {
				head->next = l1;
				l1 = l1->next;
			} else {
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		if(l1) {
			head->next = l1;
		} else if(l2) {
			head->next = l2;
		}
		return dummy.next;
	}
}