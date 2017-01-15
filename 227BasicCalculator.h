//  LeetCode
//
//  Created by Hongyan on 01/12/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int calculate(string s) {
		stack<int> sk;
		int res = 0;
		int num = 0;
		int sign = 1;
		for(int i = 0; i < s.length(); i++) {
			if(isdigit(s[i])) {
				num = num * 10 + (s[i] - '0');
			} else if (s[i] == '+') {
				res += sign * num;
				num = 0;
				sign = 1;
			} else if (s[i] == '-') {
				res += sign * num;
				num = 0;
				sign = -1;
			} else if (s[i] == '(') {
				sk.push(res);
				sk.push(sign);
				res = 0;
				num = 0;
				sign = 1;
			} else if (s[i] == ')') {
				res += sign * num;
				num = 0;
				res *= sk.top();
				sk.pop();
				res += sk.top();
				sk.pop();
				sign = 1;
			}
		}

		if(num != 0) res += sign * num;
		return res;

	}
};