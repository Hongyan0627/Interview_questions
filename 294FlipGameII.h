//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	bool dfs(unordered_map<string, bool>& memory, string& s) {
		if(memory.find(s) == memory.end()) {
			for(int i = 1; i < s.length(); i++) {
				if(s[i] == '+' && s[i-1] == '+') {
					s[i] = '-';
					s[i-1] = '-';
					bool flag = !dfs(memory, s);
					s[i] = '+';
					s[i-1] = '+';
					if(flag) {
						return true;
					}
				}
			}
			memory[s] = false;
		}
		return memory[s];
	}
public:
    bool canWin(string s) {
		if(s.length() < 2) return false;
		unordered_map<string, bool> memory;
		return dfs(memory, s);
	}
};