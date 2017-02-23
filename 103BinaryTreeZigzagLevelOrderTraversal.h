//  LeetCode
//
//  Created by Hongyan on 02/23/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		TreeNode* curr = root;
		vector<vector<int>> res;
		queue<TreeNode*> q;
		if(!root) return res;
		q.push(curr);
		while(!q.empty()) {
			vector<int> tmp;
			int sz = q.size();
			for(int i = 0; i < sz; i++) {
				curr = q.front();
				q.pop();
				tmp.push_back(curr->val);
				if(curr->left) q.push(curr->left);
				if(curr->right) q.push(curr->right);
			}
			res.push_back(tmp);
		}

		for(int i = 1; i < res.size(); i = i + 2) {
			reverse(res[i].begin(), res[i].end());
		}
		return res;
	}
};