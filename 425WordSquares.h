//  LeetCode
//
//  Created by Hongyan on 01/17/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	struct TrieNode {
		vector<int> indexs;
		TrieNode* children[26];
		TrieNode() {
			memset(children, 0, sizeof(children));
		}
	};

	TrieNode* buildTrie(vector<string>& words) {
		TrieNode* root = new TrieNode();
		for(int i = 0; i < words.size(); i++) {
			TrieNode* curr = root;
			for(auto c:words[i]) {
				if(!curr->children[c - 'a']) {
					curr->children[c - 'a'] = new TrieNode();
				}
				curr = curr->children[c - 'a'];
				curr->indexs.push_back(i);
			}
		}
		return root;
	}

	void dfs(vector<string>& words, vector<vector<string>>& res, vector<string>& curr, int level, int num, TrieNode* root) {
		if(level == num) {
			res.push_back(curr);
			return;
		}

		string str = "";
		for(int i = 0; i < level; i++) {
			str += curr[i][level];
		}

		TrieNode* node = root;

		for(auto c:str) {
			if(!node->children[c - 'a']) {
				return;
			} 
			node = node->children[c - 'a'];
		}

		for(int idx:node->indexs) {
			curr[level] = words[idx];
			dfs(words, res, curr, level + 1, num, root);
		}
	}

	vector<vector<string>> wordSquares(vector<string>& words) {
	    vector<vector<string>> res;
	    if(words.empty()) return res;
	    int num = words[0].length();
	    vector<string> curr;
	    curr.resize(num);
	    
	    TrieNode* root = buildTrie(words);
	    
	    for(auto word:words) {
	    	curr[0] = word;
	    	dfs(words, res, curr, 1, num, root);
	    }

	    return res;
    }
};