//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	vector<int> helper(TreeNode* root) {
		vector<int> res(2,0);
		if(!root) return res;
		vector<int> left = helper(root->left);
		vector<int> right = helper(root->right);
		res[0] = max(left[0], left[1]) + max(right[0], right[1]);
		res[1] = root->val + left[0] + right[0];
		return res;
	}
public:
	int rob(TreeNode* root) {
		vector<int> tmp = helper(root);
		return max(tmp[0], tmp[1]);
	}
};