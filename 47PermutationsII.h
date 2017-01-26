//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	bool nextPermutation(vector<int>& nums) {
		int k = -1;
		for(int i = nums.size() - 2; i >= 0; i--) {
			if(nums[i] < nums[i+1]) {
				k = i;
				break;
			}
		}
		if(k == -1) {
			return false;
		}

		int l = -1;
		for(int i = nums.size() - 1; i > k; i--) {
			if(nums[i] > nums[k]) {
				l = i;
				break;
			}
		}

		swap(nums[k], nums[l]);

		reverse(nums.begin() + k + 1, nums.end());
		return true;
	}
public:
	 vector<vector<int>> permuteUnique(vector<int>& nums) {
	 	vector<vector<int>> res;
	 	sort(nums.begin(), nums.end());
	 	res.push_back(nums);
	 	while(nextPermutation(nums)) {
	 		res.push_back(nums);
	 	}
	 	return res;
	 }
};