//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	TreeNode* helper(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend) {
		if(instart >= inend || poststart >= postend) return NULL;
		TreeNode* root = new TreeNode(postorder[postend-1]);
		int pos;
		for(int i = 0; i < inorder.size(); i++) {
			if(inorder[i] == root->val) {
				pos = i;
				break;
			}
		}
		int leftSize = pos - instart;
		int rightSize = inend - pos - 1;
		root->left = helper(inorder, instart, pos, postorder, poststart, poststart + pos - instart);
		root->right = helper(inorder, pos + 1, inend, postorder, poststart + pos - instart, postend-1);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) return NULL;
		return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
};