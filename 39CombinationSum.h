//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int target, int pos) {
		if(target == 0) {
			res.push_back(curr);
			return;
		} else if (target < 0) {
			return;
		} else {
			for(int i = pos; i < candidates.size(); i++) {
				curr.push_back(candidates[i]);
				dfs(res, curr, candidates, target - candidates[i], i);
				curr.pop_back();
				while(i < (candidates.size() - 1) && candidates[i] == candidates[i+1]) i++;
			}
		}
	}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	vector<vector<int>> res;
    	sort(candidates.begin(), candidates.end());
    	if(candidates.empty() || target < candidates[0]) return res;
    	vector<int> curr;
    	dfs(res, curr, candidates, target, 0);
    }
};