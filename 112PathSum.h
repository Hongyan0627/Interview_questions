//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if(!root) return false;
		if(sum == root->val && !root->left && !root->right) return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};