//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> mymap(128,0);
		for(auto c:t) mymap[c]++;
		int begin = 0, end = 0, counter = t.length(), d = INT_MAX;
	    bool flag = false;
	    int min_index;
	    while(end < s.length()) {
	    	if(mymap[s[end]] > 0) {
	    		counter--;
	    	}
	    	mymap[s[end]]--;
	    	end++;

	    	while(counter == 0) {
	    		if(!flag) flag = true;
	    		if(end - begin < d) {
	    			d = end - begin;
	    			min_index = begin;
	    		}
	 
	    		if(mymap[s[begin]] >= 0) {
	    			counter++;
	    		}
	    		mymap[s[begin]]++;
	    		begin++;
	    	}
	    }

	    if(!flag) return "";
	    return s.substr(min_index, d);

	}
};