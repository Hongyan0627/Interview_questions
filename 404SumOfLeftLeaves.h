//  LeetCode
//
//  Created by Hongyan on 02/05/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if(!root) return 0;
		int left, right;
		if(root->left && !(root->left->left) && !(root->left->right)) {
			left = root->left->val;
		} else {
			left = sumOfLeftLeaves(root->left);
		}
		right = sumOfLeftLeaves(root->right);
		return left + right;
	}
};