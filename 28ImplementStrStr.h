//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
    int strStr(string haystack, string needle) {
    	int l2 = needle.size();
    	int l1 = haystack.size();
    	if(l2 > l1) return -1;
    	if(l2 == 0) return 0;
    	if(l2 == 1) {
    		for(int i = 0; i < l1; i++) {
    			if(haystack[i] == needle[0]) {
    				return i;
    			}
    		}
    		return -1;
    	}
    	vector<int> nxt(l2, 0);
    	int i = 1, j = 0;
    	while(i < l2) {
    		if(needle[i] == needle[j]) {
    			nxt[i] = j + 1;
    			i++;
    			j++;
    		} else {
    			if(j != 0) {
    				j = nxt[j-1];
    			} else {
    				nxt[i] = 0;
    				i++;
    			}
    		}
    	}
    	j = 0;
    	i = 0;
    	while(i < l1) {
    		if(haystack[i] == needle[j]) {
    			i++;
    			j++;
    		}
    		if(j == l2) {
    			return i - j;
    		} else if (i < l1 && needle[j] != haystack[i]) {
    			if(j != 0) {
    				j = nxt[j-1];
    			} else {
    				i++;
    			}
    		}
    	}
    	return -1;
    }
}