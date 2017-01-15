//  LeetCode
//
//  Created by Hongyan on 01/12/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> nums_to_string = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> res;
		if(digits.empty()) return res;
		res.push_back("");

		for(int i = 0; i < digits.size(); i++) {
			int num = digits[i] - '0';
			if(num <= 1 || num > 9) continue;
			string candidate = nums_to_string[num];

			vector<string> tmp;
			for(int j = 0; j < candidate.length(); j++) {
				for(int k = 0; k < res.size(); k++) {
					tmp.push_back(res[k] + candidate[j]);
				}
			} 

			res.swap(tmp);
		}
		return res;
	}
};