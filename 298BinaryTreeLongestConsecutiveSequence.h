//  LeetCode
//
//  Created by Hongyan on 02/23/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	int helper(TreeNode* root, TreeNode* parent, int len) {
		if(!root) return 0;
		len = (parent && root->val == (parent->val + 1)) ? len + 1 : 1;
		return max(len, max(helper(root->left, root, len), helper(root->right, root, len)));
	}
public:
	int longestConsecutive(TreeNode* root) {
		return helper(root, NULL, 0);
	}
};