//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<vector<int>>& res, vector<int>& curr, int k, int n, int pos) {
		if(curr.size() == k) {
			if(n == 0) {
				res.push_back(curr);
			}
			return;
		} else if (curr.size() > k || n < 0) {
			return;
		} else {
			for(int i = pos; i <= 9; i++) {
				curr.push_back(i);
				dfs(res, curr, k, n - i, i + 1);
				curr.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> curr;
		dfs(res, curr, k, n, 1);
		return res;
	}
};