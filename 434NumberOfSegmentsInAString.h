//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    int countSegments(string s) {
    	int count = 0;
    	int i = 0;
    	while(i < s.length()) {
    		if(s[i] == ' ') {
    			i++;
    		} else {
    			count++;
    			while(i < s.length() && s[i] != ' ') {
    				i++;
    			}
    		}
    	}
    	return count;
    }
}