//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int maximumGap(vector<int>& nums) {
	 int n = nums.size();
	 if(n < 2) return 0;
	 int min_val = nums[0];
	 int max_val = nums[0];
	 for(int i = 1; i < nums.size(); i++) {
	 	if(nums[i] < min_val) {
	 		min_val = nums[i];
	 	} else if (nums[i] > max_val) {
	 		max_val = nums[i];
	 	}
	 }
	 
	 int gap = (int)(ceil((max_val - min_val) * 1.0 / (n - 1)));
	 
	 vector<int> bucketMin(n-1, INT_MAX);
	 vector<int> bucketMax(n-1, INT_MIN);
	 
	 for(int num:nums) {
	 	if(num == min_val || num == max_val) continue;
	 	int k = (num - min_val)/gap;
	 	bucketMax[k] = max(bucketMax[k], num);
	 	bucketMin[k] = min(bucketMin[k], num);
	 }

	 int previous = min_val;
	 int res = INT_MIN;
	 for(int i = 0; i < n - 1; i++) {
	 	if(bucketMax[i] == INT_MIN) continue;
	 	res = max(res, bucketMin[i] - previous);
	 	previous = bucketMax[i];
	 }

	 res = max(res, max_val - previous);
	 return res;
    }
};