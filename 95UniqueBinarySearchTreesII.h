//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	vector<TreeNode*> helper(int start, int end) {
		vector<TreeNode*> res;
		if(start > end) {
			res.push_back(NULL);
			return res;
		}
		for(int i = start; i <= end; i++) {
			vector<TreeNode*> leftTree = helper(start, i - 1);
			vector<TreeNode*> rightTree = helper(i+1, end);
			for(int j = 0; j < leftTree.size(); j++) {
				for(int k = 0; k < rightTree.size(); k++) {
					TreeNode* root = new TreeNode(i);
					root->left = leftTree[j];
					root->right = rightTree[k];
					res.push_back(root);
				}
			}

		}
		return res;
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res = helper(1,n);
		return res;
	}
};