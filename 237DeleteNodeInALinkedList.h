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
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		ListNode* tmp = node->next;
		node->next = tmp->next;
		delete tmp;
	}
}