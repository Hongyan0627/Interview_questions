//Leetcode 23 Merge k sorted list

#ifndef mergeksortedlist_h
#define mergeksortedlist_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(l1 && l2){
            int val1 = l1->val;
            int val2 = l2->val;
            if(val1 < val2){
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1){
            p->next = l1;
        } else if(l2){
            p->next = l2;
        }
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        int n = lists.size();
        while(n > 1){
            int k = (n + 1)/2;
            for(int i = 0; i < n/2; i++){
                lists[i] = mergeTwoLists(lists[i],lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }
};

#endif