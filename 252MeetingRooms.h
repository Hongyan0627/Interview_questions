//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
	bool canAttendMeetings(vector<Interval>& intervals)  {
		if(intervals.empty()) return true;
		sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2){return i1.start < i2.start;});
		for(int i = 0; i < intervals.size() - 1; i++) {
			if(intervals[i].end > intervals[i+1].start) {
				return false;
			}
		}
		return true;
	}

};