//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		for(int l1 = 1; l1 < 4; l1++) {
			for(int l2 = 1; l2 < 4; l2++) {
				for(int l3 = 1; l3 < 4; l3++) {
					int l4 = s.length() - l1 - l2 - l3;
					if(l4 < 1 || l4 > 3) continue;
					int num1 = stoi(s.substr(0, l1));
					int num2 = stoi(s.substr(l1, l2));
					int num3 = stoi(s.substr(l1 + l2, l3));
					int num4 = stoi(s.substr(l1 + l2 + l3, l4));
					if(num1 >= 0 && num1 <= 255 && num2 >= 0 && num2 <= 255 && num3 >= 0 && num3 <= 255 && num4 >= 0 && num4 <= 255) {
						string tmp = to_string(num1) + "." + to_string(num2) + "." + to_string(num3) + "." + to_string(num4);
						if(tmp.length() == (s.length() + 3)) {
							res.push_back(tmp);
						}
					}

				}
			}
		}
		return res;
	}
};