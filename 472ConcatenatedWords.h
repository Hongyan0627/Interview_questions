//  LeetCode
//
//  Created by Hongyan on 01/17/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	bool wordBreak(unordered_set<string>& bags, string& s) {
		int n = s.length();
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		for(int i = 1; i <= n; i++) {
			for(int j = i - 1; j >= 0; j--) {
				if(dp[j] && (bags.find(s.substr(j, i - j)) != bags.end())) {
					dp[i] = true;
				}
			}
		}
		return dp[n];
	}
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> res;
		if(words.empty()) return res;

		sort(words.begin(), words.end(), [](string& word1, string& word2) {return word1.size() < word2.size();});

		unordered_set<string> bags;
		bags.insert(words[0]);

		for(int i = 1; i < words.size(); i++) {
			if(wordBreak(bags, words[i])) {
				res.push_back(words[i]);
			}
			bags.insert(words[i]);
		}

		return res;
    }
};