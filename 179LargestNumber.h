//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string res;
		vector<string> bags;
		for(auto num:nums) {
			bags.push_back(to_string(num));
		}
		sort(bags.begin(), bags.end(), [](string& num1, string& num2){return (num1 + num2 > num2 + num1);});
		for(auto str:bags) {
			res += str;
		}
		while(res.length() > 1 && res[0] == '0') {
			res.erase(0,1);
		}
		return res;
	}
};