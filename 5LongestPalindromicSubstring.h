//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	string longestPalindrome(string s) {
		if(s.empty()) return s;
		int begin = 0, end = 0, counter = 0, d = 0, start_index = 0;
		int count_odd = 0;
		vector<int> mymap(128, 0);

		while(end < s.length()) {
			if(mymap[s[end]] > 0) {
				mymap[s[end]]--;
			} else {
				mymap[s[end]]++;
			}

			
		}   
    }
};