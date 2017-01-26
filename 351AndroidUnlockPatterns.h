//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	int dfs(vector<bool>& visited, vector<vector<int>>& skipped, int k, int num) {
		if(k < 0) return 0;
		if(k == 0) return 1;
		int res = 0;
		visited[num] = true;
		for(int i = 1; i <= 9; i++) {
			if(!visited[i] && visited[skipped[num][i]]) {
				res += dfs(visited, skipped, k - 1, i);
			}
		}
		visited[num] = false;
		return res;
	}
public:
	int numberOfPatterns(int m, int n)  {
		int res = 0;
		vector<bool> visited(10, false);
		visited[0] = true;
		vector<vector<int>> skipped(10, vector<int>(10, 0));
		skipped[1][3] = 2;
		skipped[3][1] = 2;
		skipped[3][9] = 6;
		skipped[9][3] = 6;
		skipped[7][9] = 8;
		skipped[9][7] = 8;
		skipped[1][7] = 4;
		skipped[7][1] = 4;
		skipped[1][9] = 5;
		skipped[9][1] = 5;
		skipped[2][8] = 5;
		skipped[8][2] = 5;
		skipped[3][7] = 5;
		skipped[7][3] = 5;
		skipped[4][6] = 5;
		skipped[6][4] = 5;

		for(int i = m; i <= n; i++) {
			res += dfs(visited, skipped, i - 1, 1) * 4;
			res += dfs(visited, skipped, i - 1, 2) * 4;
			res += dfs(visited, skipped, i - 1, 5);
		}

		return res;
	}
};