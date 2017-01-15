//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int minMeetingRooms(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2){return i1.start < i2.start;});
		priority_queue<int, vector<int>, greater<int>> pq;

		for(Interval& i:intervals) {
			if(!pq.empty() && pq.top() <= i.start) {
				pq.pop();
			}
			pq.push(i.end);
		}

		return pq.size();
	}
};