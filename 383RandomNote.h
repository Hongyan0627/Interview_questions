//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> bags;
		for(int i = 0; i < magazine.size(); i++) {
			bags[magazine[i]]++;
		}
		for(int i = 0; i < ransomNote.size(); i++) {
			if(bags[ransomNote[i]] <= 0) {
				return false;
			} else {
				bags[ransomNote[i]]--;
			}
		}
		return true;
	}
}