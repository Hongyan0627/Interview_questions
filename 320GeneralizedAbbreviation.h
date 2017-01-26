//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<string>& res, string curr, string& word, int pos, int count) {
		if(pos == word.length()) {
			if(count > 0) {
				curr += to_string(count);
			}
			res.push_back(curr);
			return;
		}

		dfs(res, curr, word, pos + 1, count + 1);
		if(count == 0) {
			dfs(res, curr + word[pos], word, pos + 1, 0);
		} else {
			dfs(res, curr + to_string(count) + word[pos], word, pos + 1, 0);
		}
	}
public:
	vector<string> generateAbbreviations(string word) {
		vector<string> res;
		string curr = "";
		dfs(res, curr, word, 0, 0);
		return res;
	}
};