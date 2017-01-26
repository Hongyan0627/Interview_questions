//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	int dfs(vector<bool>& used, int curr, long maxVal) {
		if(curr >= maxVal) {
			return 0;
		}
		int res = 1;
		for(int i = 0; i <= 9; i++) {
			if(!used[i]) {
				used[i] = true;
				res += dfs(used, curr * 10 + i, maxVal);
				used[i] = false;
			}
		}
		return res;
	}
public:
	int countNumbersWithUniqueDigits(int n) {
		if(n > 10) {
			return countNumbersWithUniqueDigits(10);
		}

		vector<bool> used(10, false);
		int res = 1;
		long maxVal = pow(10, n);
		
		for(int i = 1; i <= 9; i++) {
			used[i] = true;
			res += dfs(used, i, maxVal);
			used[i] = false;
		}
		return res;
	}
};