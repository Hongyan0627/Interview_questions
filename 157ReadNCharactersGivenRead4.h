//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    int read(char *buf, int n) {
    	int res = 0;
    	while(n > 0) {
    		int l = read4(buf);
    		res += min(l, n);
    		buf += l;
    		if(l < 4) break;
    		n -= l;
    	}
    	return res;
    }
}