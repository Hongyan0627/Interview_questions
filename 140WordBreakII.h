//  LeetCode
//
//  Created by Hongyan on 01/17/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//
fprintf(stderr, "%s\n", );
class Solution {
private:
	vector<string> dfs(unordered_set<string>& bags, unordered_map<string, vector<string>>& memory, string& s) {
	    
		if(memory.count(s)) return memory[s];
		
		vector<string> res;
		
		if(bags.count(s)) {
			res.push_back(s);
		}
		for(int i = 1; i < s.length(); i++) {
			string str = s.substr(i);
			if(bags.count(str)) {
				string rem = s.substr(0, i);
				vector<string> prev = dfs(bags, memory, rem);
				for(int j = 0; j < prev.size(); j++) {
					prev[j] += (" " + str);
					res.push_back(prev[j]);
				}
			}
		}
		memory[s] = res;
		return res;
	}
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> bags;
		for(auto word:wordDict) bags.insert(word);
		unordered_map<string, vector<string>> memory;
		return dfs(bags, memory, s);
	}
};