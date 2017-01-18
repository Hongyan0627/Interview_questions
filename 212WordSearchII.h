//  LeetCode
//
//  Created by Hongyan on 01/17/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
private:
    struct TrieNode {
		bool isWord;
		int idx;
		TrieNode* children[26];
		TrieNode() {
			isWord = false;
			idx = 0;
			memset(children, 0, sizeof(children));
		}
	};
	TrieNode* buildTrie(vector<string>& words) {
		TrieNode* root = new TrieNode();
		for(int i = 0; i < words.size(); i++) {
			string word = words[i];
			TrieNode* curr = root;
			for(auto c : word) {
				if(!curr->children[c - 'a']) {
					curr->children[c - 'a'] = new TrieNode();
				}
				curr = curr->children[c - 'a'];
			}
			curr->isWord = true;
			curr->idx = i;
		}
		return root;
	}


	void deleteNode(TrieNode* root) {
		for(int i = 0; i < 26; i++) {
			if(root->children[i]) {
				deleteNode(root->children[i]);
			}
		}
		delete root;
		root = NULL;
	}

	void dfs(vector<vector<char>>& board, vector<string>& words, vector<string>& res, TrieNode* root, int i, int j) {
		if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;

		if(board[i][j] == 'X') return;

		char tmp = board[i][j];

		TrieNode* curr = root->children[tmp - 'a'];

		if(!curr) return;

		if(curr->isWord) {
			res.push_back(words[curr->idx]);
			curr->isWord = false;
		}

		board[i][j] = 'X';

		dfs(board, words, res, curr, i - 1, j);
		dfs(board, words, res, curr, i + 1, j);
		dfs(board, words, res, curr, i, j - 1);
		dfs(board, words, res, curr, i, j + 1);

		board[i][j] = tmp;
	}


public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		if(board.empty() || board[0].empty() || words.empty()) return res;

		TrieNode* root  = buildTrie(words);

		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board[0].size(); j++) {
				dfs(board, words, res, root, i, j);
			}
		}

		deleteNode(root);

		return res;
	}
};