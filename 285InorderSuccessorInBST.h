//  LeetCode
//
//  Created by Hongyan on 02/23/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if(!root) return NULL;
		TreeNode* curr = root;
		TreeNode* res = NULL;
		bool flag = false;
		while(curr) {
			if(!curr->left) {
			    if(flag) {
			        res = curr;
			        flag = false;
			    } else if(curr == p){
			        flag = true;
			    }
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
					if(flag) {
					    res = curr;
					    flag = false;
					} else if(curr == p) {
					    flag = true;
					}
					curr = curr->right;
				}
			}
		}
		return res;
	}
};