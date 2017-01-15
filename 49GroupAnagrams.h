//  LeetCode
//
//  Created by Hongyan on 01/12/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> mymap;
		for(int i = 0; i < strs.size(); i++) {
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			mymap[tmp].push_back(strs[i]);
		}
		for(auto it = mymap.begin(); it != mymap.end(); it++) {
			res.push_back(it->second);
		}
		return res;
	}
};