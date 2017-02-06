//  LeetCode
//
//  Created by Hongyan on 02/05/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	int pathSumCont(TreeNode* root, int sum) {
		if(!root) return 0;
		return (sum == root->val) + pathSumCont(root->left, sum - root->val) + pathSumCont(root->right, sum - root->val);

	}
public:
	int pathSum(TreeNode* root, int sum) {
		if(!root) return 0;
		return pathSum(root->left, sum) + pathSum(root->right, sum) + pathSumCont(root,sum);
	}
};