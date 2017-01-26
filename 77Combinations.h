//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<vector<int>>& res, vector<int>& curr, int n, int k, int pos) {
		if(curr.size() == k) {
			res.push_back(curr);
			return;
		}
		for(int i = pos; i <= n; i++) {
			curr.push_back(i);
			dfs(res, curr, n, k, i + 1);
			curr.pop_back();
		}
	}
public:
   vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        if(n <= 0 || k > n) return res;
        dfs(res, curr, n, k, 1);
        return res;
   }
};