//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		if(k <= 0) return 0;
		if(s.length() <= k) return s.length();

		vector<int> mymap(128,0);
		int begin = 0, end = 0, counter = 0, d = 0;
		while(end < s.length()) {
			if(mymap[s[end]] == 0) {
				counter++;
			}
			mymap[s[end]]++;
			end++;

			while(counter > k) {
				if(mymap[s[begin]] == 1) {
					counter--;
				}
				mymap[s[begin]]--;
				begin++;
			}

			d = max(d, end - begin);
		}
		return d;
	}
};