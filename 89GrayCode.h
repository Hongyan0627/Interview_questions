//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		res.push_back(0);
		for(int i = 0; i < n; i++) {
			int mask = 1 << i;
			for(int j = res.size() - 1; j >= 0; j--) {
				res.push_back(res[j] + mask);
			}
		}
		return res;
	}
};