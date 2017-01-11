//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int n1 = version1.length();
		int n2 = version2.length();
		int i = 0, j = 0;
		int num1 = 0;
		int num2 = 0;
		while(i < n1 || j < n2) {
			while(i < n1 && version1[i] != '.') {
				num1 = num1 * 10 + (version1[i] - '0');
				i++;
			}
			while(j < n2 && version2[j] != '.') {
				num2 = num2 * 10 + (version2[j] - '0');
				j++;
			}

			if(num1 > num2) {
				return 1;
			} else if (num1 < num2) {
				return -1;
			} else {
				num1 = 0;
				num2 = 0;
				i++;
				j++;
			}
		}
		return 0;
	}
}