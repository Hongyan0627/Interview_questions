//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	vector<int> res;
    	if(s.empty()) return res;
    	if(p.length() > s.length()) return res;
    	
    	vector<int> mymap(26, 0);
    	
    	for(auto c:p) mymap[c - 'a']++;

    	int begin = 0, end = 0, counter = p.length();

    	while(end < s.length()) {
    		if(mymap[s[end] - 'a'] > 0) {
    			counter--;
    		}

    		mymap[s[end] - 'a']--;
    		end++;

    		if(counter == 0) {
    			res.push_back(begin);
    		}

    		if(end - begin == p.length()) {
    			if(mymap[s[begin] - 'a'] >= 0) {
    				counter++;
    			}
    			mymap[s[begin] - 'a']++;
    			begin++;
    		}
    	}
    	return res;
    }
};