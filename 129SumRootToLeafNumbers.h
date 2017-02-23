//  LeetCode
//
//  Created by Hongyan on 02/23/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	int helper(TreeNode* root, int val){
		if(!root) return 0;
		val = val * 10 + root->val;
		if(!root->left && !root->right) {
			return val;
		}
		return helper(root->left, val) + helper(root->right, val);
	}
public:
	int sumNumbers(TreeNode* root) {
		return helper(root, 0);
	}
};