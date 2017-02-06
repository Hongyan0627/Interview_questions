//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	bool isSymmetric(TreeNode* p, TreeNode* q) {
		if(!p && !q) return true;
		if(!p && q || p && !q) return false;
		return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
	}
public:
	bool isSymmetric(TreeNode* root) {
		if(!root) return true;
		return isSymmetric(root->left, root->right);
	}
};