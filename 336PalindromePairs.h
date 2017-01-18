//  LeetCode
//
//  Created by Hongyan on 01/17/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	bool isPalindrome(string& word) {
		int i = 0, j = word.length() - 1;
		while(i <= j) {
			if(word[i] != word[j]){
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> res;
		unordered_map<string, int> mymap;
		for(int i = 0; i < words.size(); i++) {
			mymap[words[i]] = i;
		}

		for(int i = 0; i < words.size(); i++) {
			for(int j = 0; j <= words[i].length(); j++) {
				string prefix = words[i].substr(0, j);
				string suffix = words[i].substr(j);

				if(isPalindrome(prefix)) {
					reverse(suffix.begin(), suffix.end());
					if(mymap.count(suffix) && mymap[suffix] != i) {
						res.push_back({mymap[suffix], i});
					}
				}

				if(isPalindrome(suffix)) {
					reverse(prefix.begin(), prefix.end());
					if(mymap.count(prefix) && mymap[prefix] != i && !suffix.empty()) {
						res.push_back({i, mymap[prefix]});
					}
				}
			}
		}

		return res;
	}
};