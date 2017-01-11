//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
    	unordered_map<string, vector<string>> bags;
    	for(int i = 0; i < strings.size(); i++) {
    		string tmp = "";
    		for(int j = 0; j < strings[i].size(); j++) {
    			tmp += ((strings[i][j] - strings[i][0]) + 26) % 26 + 'a';
    		}
    		bags[tmp].push_back(strings[i]);
    	}
    	vector<vector<string>> res;
    	auto it = bags.begin();
    	while(it != bags.end()) {
    		res.push_back(it->second);
    		it++;
    	}
    	return res;
    }
}