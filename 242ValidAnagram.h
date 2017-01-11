//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> mymap(128,0);
		for(auto c:t) mymap[c]++;
		for(auto c:s) mymap[c]--;
		for(auto num:mymap) {
			if(num != 0) return false;
		}
		return true;
	}
};