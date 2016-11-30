// Find the maximum repeating number in an array with len n, all elements in 
// range from 0 to k.

#ifndef FindTheMaximumRepeatingNumber_h
#define FindTheMaximumRepeatingNumber_h

#include <iostream>
#include <vector>

using namespace std;

int maxRepeating(vector<int>& nums, int k) {
	int n = nums.size();
	for(int i = 0; i < n; i++) {
		nums[nums[i] % k] += k;
	}

	int max_repeat = 0, max_num = nums[0];
	for(int i = 1; i < n; i++) {
		if(nums[i] > max_num) {
			max_num = nums[i];
			max_repeat = i;
			nums[i] = nums[i] % k;
		}
	}
	return max_repeat;
}

#endif
