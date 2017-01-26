//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int pos, int target) {
		if(target == 0) {
			res.push_back(curr);
			return;
		} else if(target < 0) {
			return;
		} else {
			for(int i = pos; i < candidates.size(); i++) {
				curr.push_back(candidates[i]);
				dfs(res, curr, candidates, i + 1, target - candidates[i]);
				curr.pop_back();
				while(i < candidates.size() - 1 && candidates[i] == candidates[i+1]) i++;
			}
		}
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> curr;
		sort(candidates.begin(), candidates.end());
		dfs(res, curr, candidates, 0, target);
		return res;
	}
};