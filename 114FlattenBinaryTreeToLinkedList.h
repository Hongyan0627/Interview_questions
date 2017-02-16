//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
void flatten(TreeNode* root) {
	TreeNode* curr = root;
	while(curr) {
		if(curr->left) {
			TreeNode* prev = curr->left;
			while(prev->right) {
				prev = prev->right;
			}
			prev->right = curr->right;
			curr->right = curr->left;
			curr->left  = NULL;
		}
		curr = curr->right;
	}
}	
};