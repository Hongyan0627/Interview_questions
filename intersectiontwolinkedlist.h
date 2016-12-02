//Leetcode 160 Intersection of two linekd list

#ifndef intersectiontwolinkedlist_h
#define intersectiontwolinkedlist_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int lenA = 1, lenB = 1;
        while(p1->next) {
        	p1 = p1->next;
        	lenA++;
        }
        while(p2->next) {
        	p2 = p2->next;
        	lenB++;
        }
        if(p1 == p2) {
            p1 = headA;
            p2 = headB;
            if(lenA > lenB) {
            	for(int i = 0; i < (lenA - lenB); i++) {
            		p1 = p1->next;
            	}
            } else {
            	for(int i = 0; i < (lenB - lenA); i++) {
            		p2 = p2->next;
            	}
            }
            while(p1 && p2) {
            	if(p1 == p2) {
            		return p1;
            	} else {
            		p1 = p1->next;
            		p2 = p2->next;
            	}
            }
        } 
        return NULL;
        

    }
};

#endif 