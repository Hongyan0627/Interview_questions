//  LeetCode
//
//  Created by Hongyan on 01/12/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int longestSubstring(string s, int k) {
	      if(k <= 0) return s.length();
	      if(k > s.length()) return 0;
	      vector<int> mymap(26,0);
	      for(auto c:s) mymap[c - 'a']++;
	      int n = s.length();
	      for(int i = 0; i < n; i++) {
	      	if(mymap[s[i] - 'a'] < k) {
	      		int l1 = longestSubstring(s.substr(0, i), k);
	      		int l2 = longestSubstring(s.substr(i+1,n - i - 1), k);
	      		return max(l1, l2);
	      	}
	      }
	      return s.length();
    }
};