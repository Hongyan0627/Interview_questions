//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		if(intervals.size() < 1) return res;
		sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2){return i1.start < i2.start;});
		
		int start = intervals[0].start;
		int end = intervals[0].end;
		for(int i = 1; i < intervals.size(); i++) {
			if(intervals[i].start > end) {
				res.push_back(Interval(start, end));
				start = intervals[i].start;
				end = intervals[i].end;
			} else {
				end = max(end, intervals[i].end);
			}
		}
		res.push_back(Interval(start, end));
		return res;
	}
};