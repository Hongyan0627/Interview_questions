//  LeetCode
//
//  Created by Hongyan on 01/31/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	TreeNode* buildBST(vector<int>& nums, int start, int end) {
		if(end <= start) return NULL;
		int mid = (end - start)/2 + start;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = buildBST(nums,start, mid);
		root->right = buildBST(nums, mid + 1, end);
		return root;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return buildBST(nums, 0, nums.size());
	}
};