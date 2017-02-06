//  LeetCode
//
//  Created by Hongyan on 02/05/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public: 
    int closestValue(TreeNode* root, double target) {
    	int res;
    	double minError = numeric_limits<double>::max();
    	TreeNode* curr = root;
    	while(curr) {
    		if(curr->val == target) {
    			return curr->val;
    		}

    		if(abs(target - curr->val) < minError) {
    			res = curr->val;
    			minError = abs(target - curr->val);
    		}

    		if(curr->val > target) {
    			curr = curr->left;
    		} else {
    			curr = curr->right;
    		}
    	}
    	return res;
    }	
};