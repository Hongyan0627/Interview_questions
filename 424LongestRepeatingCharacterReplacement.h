//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int characterReplacement(string s, int k) {
		if(k >= s.length()) return s.length();
		if(k < 0) k = 0;
		vector<int> mymap(26,0);
		int begin = 0, end = 0, counter = 0, d = 0;
		int maxCount = 0;
		while(end < s.length()) {
			mymap[s[end] - 'A']++;
			maxCount = max(maxCount, mymap[s[end] - 'A']);
			end++;

			counter = end - begin - maxCount;
			while(counter > k) {
				mymap[s[begin] - 'A']--;
				begin++;
				for(int i = 0; i < 26; i++) {
					maxCount = max(maxCount, mymap[i]);
				}
				counter = end - begin - maxCount;
			}

			d = max(d, end - begin);
		}
		return d;
	}
};