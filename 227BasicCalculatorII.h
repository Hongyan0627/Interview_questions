//  LeetCode
//
//  Created by Hongyan on 01/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int calculate(string s) {
	    istringstream in("+" + s + "+");
	    long total = 0;
	    long term = 0;
	    long n;
	    char op;
	    while(in >> op) {
	    	if(op == '+' || op == '-') {
	    		total += term;
	    		in >> term;
	    		term = term * (op == '+' ? 1 : -1);
	    	} else {
	    		in >> n;
	    		if(op == '*') {
	    			term *= n;
	    		} else {
	    			term /= n;
	    		}
	    	}
	    }
	    return total;    
    }
};