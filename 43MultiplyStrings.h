//  LeetCode
//
//  Created by Hongyan on 01/12/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	string multiply(string num1, string num2) {
	    if(num1.length() > num2.length()) return multiply(num2, num1);
	    string res(111 * 111, '0');
	    reverse(num1.begin(), num1.end());
	    reverse(num2.begin(), num2.end());
	    for(int i = 0; i < num1.length(); i++) {
	    	int carry = 0;
	    	int sum = 0;
	    	int j;
	    	for(j = 0; j < num2.length(); j++) {
	    		sum = carry + (num1[i] - '0') * (num2[j] - '0') + (res[i + j] - '0');
	    		carry = sum / 10;
	    		res[i + j] = (sum % 10) + '0';
	    	}
	    	while(carry > 0) {
	    		sum = carry + res[i + j] - '0';
	    		carry = sum/10;
	    		res[i+j] = (sum % 10) + '0';
	    		j++;
	    	}
	    }   

	    int i;
	    for(i = res.length() - 1; i >= 0; i--) {
	    	if(res[i] != '0') {
	    		break;
	    	}
	    }

	    string res2 = res.substr(0, i + 1);
	    if(res2.empty()) return "0";
	    reverse(res2.begin(), res2.end());
	    return res2;
    }
};