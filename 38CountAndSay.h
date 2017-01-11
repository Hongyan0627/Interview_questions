//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    string countAndSay(int n) {
    	if(n < 1) return "";
    	string res = "1";
    	while(n >= 2) {
    		string tmp = "";
    		int count = 1;
    		char prev = res[0];
    		for(int j = 1; j < res.size(); j++) {
    			if(res[j] == prev) {
    				count++;
    			} else {
    				tmp += to_string(count);
    				tmp += prev;
    				prev = res[j];
    				count = 1;
    			}
    		}
    		if(count > 0) {
    			tmp += to_string(count);
    			tmp += prev;
    		}
    		res = tmp;
    		n--;
    	}
    	return res;
    }
}