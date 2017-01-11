//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    string reverseString(string s) {
    	string new_str;
    	for(int i = s.length()-1; i >= 0; i--) {
    		new_str += s[i];
    	}
    	return new_str;
    }
}