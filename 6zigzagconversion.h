//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> bags(numRows, "");
        int i = 0; 
        int len = s.length();
        while(i < len) {
        	for(int j = 0; j < numRows && i < len; j++) {
        		bags[j] += s[i];
        		i++;
        	} 
        	for(int j = numRows - 2; j >= 1 && i < len; j--) {
        		bags[j] += s[i];
        		i++;
        	}
        }   
        for(int j = 1;j < bags.size(); j++) {
        	bags[0] += bags[j];
        }
        return bags[0];
    }
}