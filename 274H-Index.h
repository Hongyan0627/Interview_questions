//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	// sorting method
	// int hIndex(vector<int>& citations) {
	// 	sort(citations.begin(), citations.end());
	// 	int h = 0;
	// 	int n = citations.size();
	// 	for(int i = 0; i < n; i++) {
	// 		int tmp = min(citations[i], n - i);
	// 		h = max(h, tmp);
	// 	}
	// 	return h;
	// }
	

	// non-sorting, extra space
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> bucket(n+1,0);
		for(auto c:citations) {
			if(c > n) {
				bucket[n]++;
			} else {
				bucket[c]++;
			}
		}
		int num_papers = 0;
		for(int i = n; i >= 0; i--) {
			num_papers += bucket[i];
			if(num_papers >= i) {
				return i;
			}
		}
		return 0;
	}
};