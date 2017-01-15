//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if(nums.size() <= 1) return;
		int n = nums.size();
		int i = 0, j = 0, k = n - 1;
		while(j <= k) {
			if(nums[j] < 1) {
				swap(nums[i++], nums[j++]);
			} else if (nums[j] > 1) {
				swap(nums[j], nums[k--]);
			} else {
				j++;
			}
		} 
	}
};