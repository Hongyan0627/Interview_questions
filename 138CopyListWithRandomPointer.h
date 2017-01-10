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

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x):val(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if(!head) return NULL;
		RandomListNode* p = head;
		while(p) {
			RandomListNode* new_node = new RandomListNode(p->label);
			new_node->next = p->next;
			p->next = new_node;
			p = new_node->next;
		}

		p = head;
		while(p) {
			if(p->random) {
				p->next->random = p->random->next;
			}
			p = p->next->next;
		}

		RandomListNode dummy(0);
		dummy.next = head->next;
		p = head->next;
		while(head) {
			head->next = p->next;
			head = head->next;
			if(head) {
				p->next = head->next;
				p = p->next;
			}
		}
		return dummy.next;
	}
}