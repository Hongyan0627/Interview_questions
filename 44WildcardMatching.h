//  LeetCode
//
//  Created by Hongyan on 01/25/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, star = -1, pos = 0;
		while(i < s.length()) {
			if(j < p.length() && (p[j] == '?' || s[i] == p[j])) {
				i++;
				j++;
			} else if (j < p.length() && p[j] == '*') {
				pos = i;
				star = j;
				j++;
			} else if (star != -1) {
				j = star + 1;
				i = pos++;
			} else {
				return false;
			}
		}

		while(j < p.length() && p[j] == '*') {
			j++;
		}
		return j == p.length();
	}
};