//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
  int romanToInt(string s) {
  	int bags[26];
  	bags['I' - 'A'] = 1;
  	bags['V' - 'A'] = 5;
  	bags['X' - 'A'] = 10;
  	bags['L' - 'A'] = 50;
  	bags['C' - 'A'] = 100;
  	bags['D' - 'A'] = 500;
  	bags['M' - 'A'] = 1000;

  	int n = s.length();
  	if(n < 1) return 0;
  	int res = bags[s[n-1] - 'A'];
  	if(n == 1) return res;
  	for(int i = n-2; i >= 0; i--) {
  		if(bags[s[i] - 'A'] < bags[s[i+1] - 'A']) {
  			res -= bags[s[i] - 'A'];
  		} else {
  			res += bags[s[i] - 'A'];
  		}
  	}
  	return res;
  }   
}