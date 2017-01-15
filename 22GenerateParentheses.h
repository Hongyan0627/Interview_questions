//  LeetCode
//
//  Created by Hongyan on 01/12/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
void helper(vector<string>& res, string s, int n, int m) {
	if(n == 0 && m == 0) {
		res.push_back(s);
		return;
	}
	if(n > 0) helper(res, s + '(', n - 1, m + 1);
	if(m > 0) helper(res, s + ')', n, m - 1);
}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		helper(res, "", n, 0);
		return res;
	}
};