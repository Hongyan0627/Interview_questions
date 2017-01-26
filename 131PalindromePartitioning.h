//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<vector<string>>& res, vector<string>& curr, string& s, int pos) {
		if(pos == s.length()) {
			res.push_back(curr);
			return;
		}
		for(int i = pos; i < s.length(); i++) {
			if(isPalindrome(s, pos, i)) {
				curr.push_back(s.substr(pos, i - pos + 1));
				dfs(res, curr, s, i + 1);
				curr.pop_back();
			}
		}
	}
	bool isPalindrome(string& word, int i, int j) {
		while(i < j) {
			if(word[i] != word[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> curr;
		dfs(res, curr, s, 0);
		return res;
	}
};