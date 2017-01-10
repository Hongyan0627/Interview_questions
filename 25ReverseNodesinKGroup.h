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
	ListNode *reverseKGroup(ListNode *head, int k) {
		if(!head || k == 1) return head;
		ListNode* curr = head;
		int n = 0;
		while(curr) {
			n++;
			curr = curr->next;
		}
		ListNode dummy(0);
		dummy.next = head;
		ListNode* pre = &dummy;
		ListNode* nxt;
		while(n >= k) {
			curr = pre->next;
			nxt = curr->next;
			for(int i = 1; i < k; i++) {
				curr->next = nxt->next;
				nxt->next = pre->next;
				pre->next = nxt;
				nxt = curr->next;
			}
			pre = curr;
			n -= k;
		}
		return dummy.next;
	}
}