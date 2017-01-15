//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		if(n <= 1) return;
		auto mid_it = nums.begin() + n/2;
		nth_element(nums.begin(), mid_it, nums.end());
		int mid = *mid_it;

		#define A(i) nums[(1 + 2*i) % (n | 1)]

		int i = 0, j = 0, k = n - 1;
		while(j <= k) {
			if(A(j) > mid) {
				swap(A(i++), A(j++));
			} else if (A(j) < mid) {
				swap(A(j), A(k--));
			} else {
				j++;
			}
		}
	}
};