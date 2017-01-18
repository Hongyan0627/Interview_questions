//  LeetCode
//
//  Created by Hongyan on 01/17/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//


struct TrieNode {
	bool isWord;
	TrieNode* children[26];
	TrieNode() {
		isWord = false;
		memset(children, 0, sizeof(children));
	}
};

class WordDictionary {
private:
	TrieNode* root;
	bool searcHelper(TrieNode* curr, string& s, int pos) {
		if(!curr) return false;
		if(pos == s.length()) return curr->isWord;

		if(s[pos] != '.') {
			return searcHelper(curr->children[s[pos] - 'a'], s, pos + 1);
		} else {
			for(int i = 0; i < 26; i++) {
				if(searcHelper(curr->children[i], s, pos + 1)) {
					return true;
				}
			}
			return false;
		}
	}
public:
	WordDictionary () {
		root = new TrieNode();
	}

	~WordDictionary () {
		delete root;
	}

	void addWord(string word) {
		TrieNode* curr = root;
		for(auto c : word) {
			if(!curr->children[c - 'a']) {
				curr->children[c - 'a'] = new TrieNode();
			}
			curr = curr->children[c - 'a'];
		}
		curr->isWord = true;
	}

	bool search(string word) {
		return searcHelper(root, word, 0);
	}
};