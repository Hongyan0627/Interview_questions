//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string res = "";
    	if(strs.empty()) return res;
    	int pos = 0;
    	bool flag = true;
    	while(flag) {
    		if(pos >= strs[0].size()) break;
    		char c = strs[0][pos];
    		for(int i = 1; i < strs.size(); i++) {
    			if(strs[i].size() <= pos || strs[i][pos] != c) {
    				flag = false;
    				break;
    			}
    		}
    		if(flag) {
    			res += c;
    			pos++;
    		}
    	}
    	return res;
    }
}