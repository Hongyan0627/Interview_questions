//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	bool nextPermutation(string& word) {
		int k = -1;
		for(int i = word.length() - 2; i >= 0; i--) {
			if(word[i] < word[i+1]) {
				k = i;
				break;
			}
		}

		if(k == -1) {
			return false;
		}

		int l = -1;
		for(int i = word.length() - 1; i >= 0; i--) {
			if(word[i] > word[k]) {
				l = i;
				break;
			}
		}

		swap(word[k], word[l]);

		reverse(word.begin() + k + 1, word.end());
		return true;
	}
	string getStr(string& word, string oddChar) {
		string tmp = word;
		reverse(tmp.begin(), tmp.end());
		tmp = word + oddChar + tmp;
		return tmp;
	}
public:
	vector<string> generatePalindromes(string s) {
		vector<string> res;
		unordered_map<char, int> mymap;
		for(auto c:s) {
			mymap[c]++;
		}

		string mystring = "";
		string oddChar = "";
		int count = 0;
		for(auto it = mymap.begin(); it != mymap.end(); it++) {
			if(it->second % 2 == 0) {
				for(int i = 0; i < it->second / 2; i++) {
					mystring += it->first;
				}
			} else {
				count++;
				if(count > 1) {
					return res;
				}
				oddChar.push_back(it->first);
				for(int i = 0; i < (it->second - 1) / 2; i++) {
					mystring += it->first;
				}
 			}
		}

		sort(mystring.begin(), mystring.end());

		res.push_back(getStr(mystring, oddChar));
		while(nextPermutation(mystring)) {
			res.push_back(getStr(mystring, oddChar));
		}

		return res;
	}
};