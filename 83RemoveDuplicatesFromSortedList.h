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
	ListNode* deleteDuplicates(ListNode* head) {
		if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* p = head;
        while(p && p->next) {
        	if(p->val == p->next->val) {
        		ListNode* tmp =p->next;
        		p->next = tmp->next;
        		delete tmp;
        	} else {
        		p = p->next;
        	}
        }

        return dummy.next;
    }
}