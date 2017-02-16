//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
vector<vector<int>> levelOrder(TreeNode* p) {
	vector<vector<int>> res;
	queue<TreeNode*> myqueue;
	if(!p) return res;
	myqueue.push(p);
	while(!myqueue.empty()) {
		vector<int> curr;
		int sz = myqueue.size();
		for(int i = 0; i < sz; i++) {
			TreeNode* node = myqueue.front();
			myqueue.pop();
			curr.push_back(node->val);
			if(node->left) {
				myqueue.push(node->left);
			}
			if(node->right) {
				myqueue.push(node->right);
			}
		}
		res.push_back(curr);
	}
	return res;
  }	
};