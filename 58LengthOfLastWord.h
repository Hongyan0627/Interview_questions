//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int lengthOfLastWord(string s) {
		int pos = s.find_last_not_of(' ');
		if(pos == string::npos) {
			return 0;
		} else {
			int l = 0;
			while(pos >= 0 && s[pos] != ' ') {
				l++;
				pos--;
			}
			return l;
		}
	}
}