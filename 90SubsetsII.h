//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int pos) {
		if(pos <= nums.size()) {
			res.push_back(curr);
		}

		for(int i = pos; i < nums.size(); i++) {
			if(i != pos && nums[i] == nums[i-1]) continue;
			curr.push_back(nums[i]);
			dfs(res, curr, nums, i + 1);
			curr.pop_back();
		}
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> curr;
		sort(nums.begin(), nums.end());
		dfs(res, curr, nums, 0);
		return res;
	}
};