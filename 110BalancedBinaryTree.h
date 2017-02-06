//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	int height(TreeNode* root) {
		if(!root) return 0;
		int leftHeight = height(root->left);
		if(leftHeight < 0) return -1;
		int rightHeight = height(root->right);
		if(rightHeight < 0) return -1;
		if(abs(leftHeight - rightHeight) <= 1) {
			return 1 + max(leftHeight, rightHeight);
		} else {
			return -1;
		}
	}
public:
	bool isBalanced(TreeNode* root) {
		return height(root) != -1;
	}
};