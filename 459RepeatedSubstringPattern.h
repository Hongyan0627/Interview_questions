//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
    	int n = str.length();
    	if(n <= 1) return false;
    	for(int i = n/2; i >= 1; i--) {
    		if(n % i == 0) {
    			int m = n/i;
    			string tmp = "";
    			string pattern = str.substr(0,i);
    			for(int j = 0; j < m; j++) {
    				tmp += pattern;
    			}
    			if(tmp == str) return true;
    		}
    	}
    	return false;
    }
}