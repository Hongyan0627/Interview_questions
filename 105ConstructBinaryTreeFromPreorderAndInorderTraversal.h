//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	TreeNode* helper(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2) {
		if(e1 <= s1 || e2 <= s2) {
			return NULL;
		}
		int root = preorder[s1];
		int pos;
		for(int i = s2; i < e2; i++) {
			if(inorder[i] == root) {
				pos = i;
				break;
			}
		}
		int left_size = pos - s2;
		int right_size = e2 - pos - 1;

		TreeNode* newRoot = new TreeNode(root);
		newRoot->left = helper(preorder, s1 + 1, s1 + 1 + pos - s2, inorder, s2, pos);
		newRoot->right = helper(preorder, s1 + 1 + pos - s2, e1, inorder, pos + 1, e2);
        return newRoot;
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}
};