//328 Odd Even Linked List

#ifndef oddevenlinkedlist_h
#define oddevenlinkedlist_h

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* secondHead = head->next;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p1->next && p2->next) {
        	p1->next = p2->next;
        	p1 = p1->next;
        	p2->next = p1->next;
        	p2 = p2->next;
        }
        p1->next = secondHead;
        return head;
    }
};

#endif 