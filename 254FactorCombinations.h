//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<vector<int>>& res, vector<int>& curr, int n) {
		int i = curr.empty() ? 2 : curr.back();
		for(; i <= n/i; i++) {
			if(n % i == 0) {
				curr.push_back(i);
				curr.push_back(n/i);
				res.push_back(curr);
				curr.pop_back();
				dfs(res, curr, n/i);
				curr.pop_back();
			}
		}
	}
public:
	vector<vector<int>> getFactors(int n) {
		vector<vector<int>> res;
		vector<int> curr;
		dfs(res, curr, n);
		return res;
	}
};