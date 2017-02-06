//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<string>& res, TreeNode* root, string curr) {
		if(!root) return;
		if(!root->left && !root->right) {
		    res.push_back(curr);
		    return;
		}
		if(root->left) {
			dfs(res, root->left, curr + "->" + to_string(root->left->val));
		}

		if(root->right) {
			dfs(res, root->right, curr + "->" + to_string(root->right->val));
		}
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if(!root) return res;
		dfs(res, root, to_string(root->val));
		return res;
	}
};