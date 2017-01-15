//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {

private:
	void findLongestPalindrome(string& s, int i, int j, int& maxLen, int& startPos ) {
		
		while(i >= 0 && j < s.length() && s[i] == s[j]) {
			i--;
			j++;
		}

		if(j - i - 1> maxLen) {
			maxLen = j - i - 1;
			startPos = i + 1;
		}
	}
public:
	string longestPalindrome(string s) {
		int n = s.length();
		if(n < 2) return s;

		int maxLen = 0;
		int startPos = 0;

		for(int i = 0; i < s.length(); i++) {
			findLongestPalindrome(s, i, i, maxLen, startPos);
			findLongestPalindrome(s, i, i + 1, maxLen, startPos);
		}

		return s.substr(startPos, maxLen);
    }
};