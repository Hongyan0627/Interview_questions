//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int minDepth(TreeNode* root) {
		if(!root) return 0;
		int res = 0;
		queue<TreeNode*> myqueue;
		myqueue.push(root);
		while(!myqueue.empty()) {
			int sz = myqueue.size();
			res++;
			for(int i = 0; i < sz; i++) {
				TreeNode* curr = myqueue.front();
				myqueue.pop();
				if(curr && !curr->left && !curr->right) {
					return res;
				}
				if(curr->left) {
					myqueue.push(curr->left);
				}
				if(curr->right) {
					myqueue.push(curr->right);
				}
			}
		}
		return res;
	}
};