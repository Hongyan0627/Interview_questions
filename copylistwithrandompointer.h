//Leetcode 138 Copy List with Random Pointer

#ifndef copylistwithrandompointer_h
#define copylistwithrandompointer_h

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        RandomListNode* p = head;
        while(p) {
        	RandomListNode* copy = new RandomListNode(p->label);
        	copy->next = p->next;
        	p->next = copy;
        	p = p->next->next;
        }

        p = head;
        while(p) {
        	if(p->random) {
        		p->next->random = p->random->next;
        	}
        	p = p->next->next;
        }

        RandomListNode dummy(0);
        RandomListNode* new_head = &dummy;
        new_head->next = head->next;
        new_head  = new_head->next;
        while(head) {
        	head->next = new_head->next;
        	head = head->next;
        	if(head){
        	   new_head->next = head->next;
        	   new_head = new_head->next; 
        	}
        }
        return dummy.next;
    }
};

#endif