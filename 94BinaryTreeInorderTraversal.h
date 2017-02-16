//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode* curr = root;
		while(curr) {
			if(!curr->left) {
				res.push_back(curr->val);
				curr = curr->right;
			} else {
				TreeNode* prev = curr->left;
				while(prev->right && prev->right != curr) {
					prev = prev->right;
				}

				if(!prev->right) {
					prev->right = curr;
					curr = curr->left;
				} else {
					prev->right = NULL;
					res.push_back(curr->val);
					curr = curr->right;
				}
			}
		}
		return res;
	}
};