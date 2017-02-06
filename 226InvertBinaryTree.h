//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(!root) return NULL;
		TreeNode* left = invertTree(root->right);
		TreeNode* right = invertTree(root->left);
		root->left = left;
		root->right = right;
		return root;
	}
};