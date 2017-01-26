//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	void dfs(vector<int>& res, vector<int>& times, int num, int pos, int sum) {
		if((times.size() == 6 && sum >= 60) || (times.size() == 4 && sum >= 12)) return;
		if(num == 0) {
			res.push_back(sum);
		}
		for(int i = pos; i < times.size(); i++) {
			dfs(res, times, num - 1, i + 1, sum + times[i]);
		}
	}
public:
	vector<string> readBinaryWatch(int num) {
		vector<int> hours = {8,4,2,1};
		vector<int> minutes = {32,16,8,4,2,1};
		vector<string> res;
		for(int i = 0; i <= num; i++) {
			vector<int> res_hours;
			vector<int> res_minutes;
			dfs(res_hours, hours, i, 0, 0);
			dfs(res_minutes, minutes, num - i, 0, 0);
			for(int j = 0; j < res_hours.size(); j++) {
				for(int k = 0; k < res_minutes.size(); k++) {
					res.push_back(to_string(res_hours[j]) + ":" + ((res_minutes[k] < 10) ? "0" : "") + to_string(res_minutes[k]));
				}
			}
		}
		return res;
	}
};