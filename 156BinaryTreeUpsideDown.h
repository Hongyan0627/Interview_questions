//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		TreeNode* curr = root;
		TreeNode* prev = NULL;
		TreeNode* next = NULL;
		TreeNode* tmp = NULL;
		while(curr) {
			next = curr->left;
			curr->left = tmp;
			tmp = curr->right;
			curr->right = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}
};