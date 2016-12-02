//Leetcode 234 Palindrome Linked list

#ifndef palindromelinkedlist_h
#define palindromelinkedlist_h

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        
        fast = slow->next;
        ListNode* p = NULL;
        slow->next = NULL;
        while(fast) {
        	ListNode* tmp = fast->next;
        	fast->next = p;
        	p = fast;
        	fast = tmp;
        }

        int len1 = 0, len2 = 0;
        ListNode* p2 = head;
        while(p2 && p) {
        	len1++;
        	len2++;
        	if(p->val != p2->val) {
        		return false;
        	} 
        	p = p->next;
        	p2 = p2->next;
        }
        while(p) {
        	p = p->next;
        	len2++;
        }
        while(p2) {
        	p2 = p2->next;
        	len1++;
        }

        return (abs(len1 - len2) <= 1);
    }
};

#endif