//  LeetCode
//
//  Created by Hongyan on 01/17/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> bags;
		
		for(int i = 0; i < wordDict.size(); i++) {
			bags.insert(wordDict[i]);
		}

		int n = s.length();

		vector<bool> dp(n+1,false);

		dp[0] = true;
		
		for(int i = 1; i <= n; i++) {
			for(int j = i - 1; j >= 0; j--) {
				if(dp[j] && bags.find(s.substr(j, i - j)) != bags.end()) {
					dp[i] = true;
					break;
				}
			}
		}

		return dp[n];
	}
}