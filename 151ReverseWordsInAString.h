//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    void reverseWords(string &s) {
    	if(s.empty()) return;
    	reverse(s.begin(), s.end());
    	int index = 0;
    	for(int i = 0; i < s.length(); i++) {
    		if(s[i] != ' ') {
    			if(index > 0) {
    				s[index] = ' ';
    				index++;
    			}
    			int j= i;
    			while(j < s.length() && s[j] != ' ') {
    				s[index] = s[j];
    				index++;
    				j++;
    			}
    			reverse(s.begin() + index - (j - i), s.begin() + index);
    			i = j;
    		}
    	}
    	s.erase(s.begin() + index, s.end());
    }
}