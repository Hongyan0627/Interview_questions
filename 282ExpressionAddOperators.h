//  LeetCode
//
//  Created by Hongyan on 01/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {

public:
	vector<string> restoreIpAddresses(string s) {
	    vector<string> res;
	    for(int l1 = 1; l1 <= 3; l1++) {
	    	for(int l2 = 1; l2 <= 3; l2++) {
	    		for(int l3 = 1; l3 <= 3; l3++) {
	    			int l4 = s.length() - (l1 + l2 + l3);
	    			if(l4 < 1 || l4 > 3) continue;
	    			int part1 = stoi(s.substr(0, l1));
	    			int part2 = stoi(s.substr(l1, l2));
	    			int part3 = stoi(s.substr(l1 + l2, l3));
	    			int part4 = stoi(s.substr(l1 + l2 + l3, l4));
	    			if(part1 <= 255 && part2 <= 255 && part3 <= 255 && part4 <= 255) {
	    				string tmp = to_string(part1) + "." + to_string(part2) + "." + to_string(part3) + "." + to_string(part4);
	    				if(tmp.length() == (s.length() + 3)) {
	    					res.push_back(tmp);
	    				}
	    			}
	    		}
	    	}
	    }
	    return res;   
    }
};