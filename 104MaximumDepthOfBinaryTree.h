//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int maxDepth(TreeNode* root) {
	    if(!root) return 0;
	    return 1 + max(maxDepth(root->left),maxDepth(root->right));   
    }
};