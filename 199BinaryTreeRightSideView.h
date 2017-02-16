//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if(!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()) {
			int sz = q.size();
			for(int i = 0; i < sz; i++) {
				TreeNode* curr = q.front();
				q.pop();
				if(curr->left) {
					q.push(curr->left);
				}
				if(curr->right) {
					q.push(curr->right);
				}
				if(i == sz - 1) {
					res.push_back(curr->val);
				}
			}
		}
		return res;
	}
};