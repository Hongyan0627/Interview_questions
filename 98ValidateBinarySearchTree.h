//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	bool helper(TreeNode* root, long low, long high){
		if(!root) return true;
		if(root->val <= low || root->val >= high) return false;
		return helper(root->left, low, root->val) && helper(root->right, root->val, high);
	}
public:
	bool isValidBST(TreeNode* root) {
		if(!root || (root && !root->left && !root->right)) return true;
		long low = LONG_MIN;
		long high = LONG_MAX;
		return helper(root, low, high);
	}
};