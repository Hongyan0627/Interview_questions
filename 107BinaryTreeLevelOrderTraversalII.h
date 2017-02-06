//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if(!root) return res;
		queue<TreeNode*> myqueue;
		myqueue.push(root);
		while(!myqueue.empty()) {
			int sz = myqueue.size();
			vector<int> tmp;
			for(int i = 0; i < sz; i++) {
				TreeNode* curr = myqueue.front();
				myqueue.pop();
				tmp.push_back(curr->val);
				if(curr->left) {
					myqueue.push(curr->left);
				}
				if(curr->right) {
					myqueue.push(curr->right);
				}
			}
			res.push_back(tmp);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};