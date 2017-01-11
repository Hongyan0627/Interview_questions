//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	vector<int> mymap(128, 0);
    	int counter = 0;
    	int begin = 0;
    	int end = 0;
    	int d = 0;
    	while(end < s.size()) {
    		if(mymap[s[end]] > 0) {
    			counter++;
    		}

    		mymap[s[end]]++;
    		end++;

    		while(counter > 0) {
    			if(mymap[s[begin]] > 1) {
    				counter--;
    			}
    			mymap[s[begin]]--;
    			begin++;
    		}

    		d = max(d, end - begin);
    	}

    	return d;
    }
}