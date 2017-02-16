//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	bool helper(TreeNode* root, int& count) {
		if(!root) return true;
		bool isLeft = helper(root->left, count);
		bool isRight = helper(root->right, count);
		if(isLeft && isRight) {
			if((!root->left || root->val == root->left->val) && (!root->right || root->val == root->right->val)) {
				count++;
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
public:
	int countUnivalSubtrees(TreeNode* root) {
		int count = 0;
		helper(root, count);
		return count;
	}
};