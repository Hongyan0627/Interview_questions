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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(!headA || !headB) return NULL;
		int lenA = 1, lenB = 1;
		ListNode* pA = headA;
		ListNode* pB = headB;
		while(pA->next) {
			pA = pA->next;
			lenA++;
		}
		while(pB->next) {
			pB = pB->next;
			lenB++;
		}

		if(pA = pB) {
			pA = headA;
			pB = headB;
			if(lenA > lenB) {
				for(int i = 0; i < lenA - lenB; i++) {
					pA = pA->next;
				}
			} else {
				for(int i = 0; i < lenB - lenA; i++) {
					pB = pB->next;
				}
			}
			while(pA != pB) {
				pA = pA->next;
				pB = pB->next;
			}
			return pA;
		} else {
			return NULL;
		}
	}
}