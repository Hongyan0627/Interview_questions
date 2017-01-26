//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
void dfs(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int pos) {
	if(pos >= nums.size()) {
		return;
	}

	for(int i = pos; i < nums.size(); i++) {
		curr.push_back(nums[i]);
		res.push_back(curr);
		dfs(res, curr, nums, i + 1);
		curr.pop_back();
	}
}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> curr;
		res.push_back(curr);
		sort(nums.begin(), nums.end());
		dfs(res, curr, nums, 0);
		return res;
	}
};