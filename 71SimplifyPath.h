//  LeetCode
//
//  Created by Hongyan on 01/12/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> sk;
		istringstream s(path);
		string tmp;
		while(getline(s, tmp, '/')) {
			if(tmp.length() == 0 || tmp == ".") continue;
			if(tmp == "..") {
				if(!sk.empty()) {
					sk.pop_back();
				} 
			} else {
				sk.push_back(tmp);
			}
		}

		string res = "";
		for(int i = 0; i < sk.size(); i++) {
			res += ("/" + sk[i]);
		}
		return res.empty() ? "/" : res;
	}
};