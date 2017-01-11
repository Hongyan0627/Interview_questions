//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
    	vector<string> res;
    	for(int i = 1; i < s.length(); i++) {
    		if(s[i] == '+' && s[i-1] == '+') {
    			s[i-1] = '-';
    			s[i] = '-';
    			res.push_back(s);
    			s[i] = '+';
    			s[i-1] = '+';
    		} 
    	}
    	return res;
    }
}