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
    ListNode* plusOne(ListNode* head) {
    	ListNode* prev = NULL;
    	ListNode* p = head;
    	while(p) {
    		ListNode* tmp = p->next;
    		p->next = prev;
    		prev = p;
    		p = tmp;
    	}
    	p = prev;
    	prev = NULL;
    	int carry = 1;
    	while(p) {
    		int sum = p->val + carry;
    		carry = sum / 10;
    		p->val = sum % 10;
    		ListNode* tmp = p->next;
    		p->next = prev;
    		prev = p;
    		p = tmp;
    	}
    	
    	if(carry > 0) {
    	    p = new ListNode(carry);
    	    p->next = prev;
    	    prev = p;
    	}
    	return prev;
    }	
}