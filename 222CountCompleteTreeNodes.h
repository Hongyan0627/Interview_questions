//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	int height(TreeNode* root) {
		if(!root) return -1;
		// subtree on left must have higher or equal height to right subtree.
		return 1 + height(root->left);
	}
public:
	int countNodes(TreeNode* root) {
		if(!root) return 0;
		int h = height(root);
		if(h == 0) {
		    return 1;
		}
		int rheight = height(root->right);
		if(rheight == (h-1)) {
			return (1 + (1 << h) - 1 + countNodes(root->right));
		} else {
			return (1 + (1 << (h-1)) - 1 + countNodes(root->left));
		}
	}
};