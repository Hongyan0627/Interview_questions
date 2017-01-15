//  LeetCode
//
//  Created by Hongyan on 01/12/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
	bool isValid(char a){
		return a != '0';
	}
	bool isValid(char a, char b) {
		return a == '1' || (a == '2' && b <= '6');
	}
public:
	int numDecodings(string s) {
		if(s.empty() || s[0] == '0') return 0;
		if(s.length() == 1) return 1;

		int n = s.length();
		
		int prev = 1;
		int curr = 1;

		for(int i = 1; i < n; i++) {
			int tmp = curr;
			if(isValid(s[i]) && isValid(s[i-1], s[i])) {
				curr = prev + tmp;
			} else if(!isValid(s[i]) && !isValid(s[i-1], s[i])) {
				return 0;
			} else if(!isValid(s[i]) && isValid(s[i-1], s[i])) {
				curr = prev;
			} else {
				curr = curr;
			}
			prev = tmp;
		}
		return curr;
	}
};