//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	bool isVowel(char c) {
		return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
	}
    string reverseVowels(string s) {
    	if(s.empty()) return s;
    	int i = 0;
    	int j = s.length() - 1;
    	while(i < j) {
    		while(i < j && !isVowel(s[i])) {
    			i++;
    		}
    		while(j > i && !isVowel(s[j])) {
    			j--;
    		}
    		if(i < j) {
    			swap(s[i], s[j]);
    			i++;
    			j--;
    		}
    	}
    	return s;
    }
}