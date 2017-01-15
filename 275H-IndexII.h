//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int hIndex(vector<int>& citations) {
	    int n = citations.size();
	    int l = 0, r = n - 1;
	    while(l <= r) {
	    	int m = (r - l)/2 + l;
	    	if(citations[m] == n - m) {
	    		return citations[m];
	    	} else if(citations[m] > (n - m)) {
	    		r = m - 1;
	    	} else {
	    		l = m + 1;
	    	}
	    }   
	    return n - r - 1;
    }

};