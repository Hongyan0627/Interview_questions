//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	bool isLetter(char c) {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
	}
    bool isPalindrome(string s) {
    	if(s.empty()) return true;
    	int i = 0, j = s.length() - 1;
    	while(i < j) {
    		while(i < j && !isLetter(s[i])) {
    			i++;
    		}
    		while(j > i && !isLetter(s[j])) {
    			j--;
    		}
    		
    		if(i == j) return true;
    		if(tolower(s[i]) != tolower(s[j])) return false;
    		i++;
    		j--;
    	}
    	return true;
    }
}