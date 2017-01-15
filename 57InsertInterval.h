//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		int n = intervals.size();
		for(int i = 0; i < intervals.size(); i++) {
			if(intervals[i].start > newInterval.start) {
				intervals.insert(intervals.begin() + i, newInterval);
				break;
			}
		}
		
		if(intervals.size() == n) {
		    intervals.push_back(newInterval);
		}

		int start  = intervals[0].start;
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