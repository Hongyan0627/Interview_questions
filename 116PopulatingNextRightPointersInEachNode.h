//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if(!root) return;
		queue<TreeLinkNode*> q;
		q.push(root);
		while(!q.empty()) {
			int sz = q.size();
			for(int i = 0; i < sz; i++) {
				TreeLinkNode* node = q.front();
				q.pop();
				if(i < sz-1) {
					node->next = q.front();
				} else {
					node->next = NULL;
				}
				if(node->left) {
					q.push(node->left);
					q.push(node->right);
				}
			}
		}
	}
};