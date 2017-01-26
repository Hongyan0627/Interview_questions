//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void nextPermutation(string& word) {
		int k = -1;
		for(int i = word.length() - 2; i >= 0; i--) {
			if(word[i] < word[i+1]) {
				k = i;
				break;
			}
		}
		if(k == -1) {
			reverse(word.begin(), word.end());
			return;
		}

		int l = -1;
		for(int i = word.length() - 1; i > k; i--) {
			if(word[i] > word[k]) {
				l = i;
				break;
			}
		}

		swap(word[k], word[l]);
		reverse(word.begin() + k + 1, word.end());
	}
public:
string getPermutation(int n, int k) {
	string sequence = "";
	for(int i = 1; i <= n; i++) {
		sequence += to_string(i);
	}

	while(k-- > 1) {
		nextPermutation(sequence);
	}

	return sequence;
}
};