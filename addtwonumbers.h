// Leetcode 2 Add two numbers
// 
#ifndef addtwonumbers_h 
#define addtwonumbers_h

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int sum = 0, carry = 0;
	ListNode dummy(0);
	ListNode* head = &dummy, *p = NULL;
	
	while(l1 || l2 || carry) {
		sum = carry;
		if(l1) {
			sum += l1->val;
			l1 = l1->next;
		}
		if(l2) {
			sum += l2->val;
			l2 = l2->next;
		}
		carry = sum / 10;
		p = new ListNode(sum % 10);
		head->next = p;
		head = p;
	}
	return dummy.next;
}

#endif