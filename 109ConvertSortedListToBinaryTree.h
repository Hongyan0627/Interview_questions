//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* buildBST(ListNode* start, ListNode* end) {
		if(start == end) return NULL;
		ListNode* slow = start;
		ListNode* fast = start;
		
		while(fast != end && fast->next != end) {
			slow = slow->next;
			fast = fast->next->next;
		}

		fast = slow->next;
		slow->next = NULL;

		TreeNode* root = new TreeNode(slow->val);
		root->left = buildBST(start, slow);
		root->right = buildBST(fast, end);
		return root;
	}
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if(!head) return NULL;
		return buildBST(head, NULL);
	}
};