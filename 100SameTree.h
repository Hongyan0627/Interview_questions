//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if(!p && !q) return true;
		if(p && !q || q && !p) return false;
		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};