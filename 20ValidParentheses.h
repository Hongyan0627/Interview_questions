//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	bool isValid(string s) {
		int n = s.length();
		if(n % 2 == 1) return false;
		stack<char> sk;
		for(int i = 0; i < n; i++) {
			if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
				sk.push(s[i]);
			} else {
				if(sk.empty()) return false;
				if((s[i] == ')' && sk.top() == '(') || (s[i] == ']' && sk.top() == '[') || (s[i] == '}' && sk.top() == '{')) {
					sk.pop();
				} else {
					return false;
				}
			}
		}
		return sk.empty();
	}   
}