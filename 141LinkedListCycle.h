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
	bool hasCycle(ListNode* head) {
		if(!head || !head->next) return false;
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast) return true;
		}
		return false;
	}
}