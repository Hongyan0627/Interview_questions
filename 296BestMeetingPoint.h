//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
	     int m = grid.size();
	     int n = grid[0].size();

	     vector<int> xIndex, yIndex;
	     for(int i = 0; i < m; i++) {
	     	for(int j = 0; j < n; j++) {
	     		if(grid[i][j] == 1) {
	     			xIndex.push_back(i);
	     			yIndex.push_back(j);
	     		}
	     	}
	     }   

	     int l = xIndex.size();

	     nth_element(xIndex.begin(), xIndex.begin() + l/2, xIndex.end());
	     nth_element(yIndex.begin(), yIndex.begin() + l/2, yIndex.end());

	     int mid_x = xIndex[l/2];
	     int mid_y = yIndex[l/2];

	     int res = 0;
	     for(int i = 0; i < l; i++) {
	     	res += abs(xIndex[i] - mid_x) + abs(yIndex[i] - mid_y);
	     }

	     return res;
    }
};