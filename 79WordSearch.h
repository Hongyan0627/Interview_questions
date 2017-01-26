//  LeetCode
//
//  Created by Hongyan on 01/24/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
	bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int pos, int i, int j) {
		int m = board.size();
		int n = board[0].size();

		if(pos == word.length()) {
			return true;
		}

		visited[i][j] = true;

		if(i > 0 && !visited[i-1][j] && board[i-1][j] == word[pos]) {
			if(dfs(board, visited, word, pos + 1, i-1, j)) {
				return true;
			}
		}

		if(i < (m-1) && !visited[i+1][j] && board[i+1][j] == word[pos]) {
			if(dfs(board, visited, word, pos + 1, i+1, j)) {
				return true;
			}
		}

		if(j > 0 && !visited[i][j-1] && board[i][j-1] == word[pos]) {
			if(dfs(board, visited, word, pos + 1, i, j-1)) {
				return true;
			}
		}

		if(j < (n-1) && !visited[i][j+1] && board[i][j+1] == word[pos]) {
			if(dfs(board, visited, word, pos + 1, i, j+1)) {
				return true;
			}
		}
		visited[i][j] = false;
		return false;

	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		if(board.empty() || board[0].empty()) return false;
		if(word.length() == 0) return true;
		int m = board.size();
		int n = board[0].size();

		vector<vector<bool>> visited(m, vector<bool>(n, false));

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(board[i][j] == word[0]) {
					if(dfs(board, visited, word, 1, i, j)) {
						return true;
					}
				}
			}
		}
		return false;
	}
};