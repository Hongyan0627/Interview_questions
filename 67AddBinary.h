//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    string addBinary(string a, string b) {
    	if(a.length() > b.length()) return addBinary(b, a);
    	string res = "";
    	int carry = 0;
    	int pos = 0;
    	int lenA = a.length(), lenB = b.length();
    	while(pos < b.length()) {
    		int sum = carry + (b[lenB - pos - 1] - '0');
    		if(pos < a.length()) {
    			sum += (a[lenA - pos - 1] - '0');
    		}
    		carry = sum / 2;
    		res += to_string(sum % 2);
    		pos++;
    	}
    	if(carry > 0){
    		res += to_string(carry);
    	}
    	reverse(res.begin(), res.end());
    	return res;
    }
}