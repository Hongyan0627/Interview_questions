//  LeetCode
//
//  Created by Hongyan on 02/23/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<vector<int> >& res, vector<int>& curr, int target, int cumsum, TreeNode* root) {
		if(!root) return;
		cumsum += root->val;
		curr.push_back(root->val);

		if(cumsum == target) {
			if(!root->left && !root->right) {
				res.push_back(curr);
				curr.pop_back();
				return;
			}
		}

		dfs(res, curr, target, cumsum, root->left);
		dfs(res, curr, target, cumsum, root->right);
		curr.pop_back();
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int> > res;
		if(!root) return res;
		vector<int> curr;
		dfs(res, curr, sum, 0, root);
		return res;
	}
};