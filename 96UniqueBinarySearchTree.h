//  LeetCode
//
//  Created by Hongyan on 02/05/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int numTrees(int n) {
		if(n <= 1) {
			return 1;
		} else {
			vector<int> dp(n + 1, 0);
			dp[0] = 1;
			dp[1] = 1;
			for(int i = 2; i <= n; i++) {
				for(int j = 1; j <= i; j++) {
					dp[i] += dp[j-1] * dp[i - j];
				}
			}
			return dp[n];
		}
	}
};