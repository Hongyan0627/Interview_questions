//  LeetCode
//
//  Created by Hongyan on 02/05/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(!root || root == p || root == q) return root;
    	TreeNode* left = lowestCommonAncestor(root->left, p, q);
    	TreeNode* right = lowestCommonAncestor(root->right,p,q);
    	if(left) return left;
    	if(right) return right;
    	return root; 
    }	
};