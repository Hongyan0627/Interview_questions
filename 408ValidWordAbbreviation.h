//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
    	int i = 0, j = 0;
    	while(i < word.length() && j < abbr.length()) {
    		if(isdigit(abbr[j])) {
    			if(abbr[j] == '0') {
    				return false;
    			}
    			int count = 0;
    			while(j < abbr.length() && isdigit(abbr[j])) {
    				count = count * 10 + abbr[j] - '0';
    				j++;
    			}
    			i += count;
    		} else {
    			if(word[i] == abbr[j]) {
    				i++;
    				j++;
    			} else {
    				return false;
    			}
    		}
    	}
    	return i ==  word.length() && j == abbr.length();
    }
}