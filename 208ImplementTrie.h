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

class Trie {
private:
	TrieNode* root;
	void deleteNode(TrieNode* curr) {
		for(int i = 0; i < 26; i++) {
			if(curr->children[i] != NULL) {
				deleteNode(curr->children[i]);
			}
		}
		delete curr;
		curr = NULL;
	}
public:
	Trie () {
		root = new TrieNode();
	}

	~Trie() {
		deleteNode(root);
	}

	void insert(string word) {
		if(search(word)) return;
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
		TrieNode* curr = root;
		for(auto c : word) {
			if(!curr->children[c - 'a']) {
				return false;
			}
			curr = curr->children[c - 'a'];
		}
		return curr->isWord;
	}

	bool startsWith(string prefix) {
		TrieNode* curr = root;
		for(auto c : prefix) {
			if(!curr->children[c - 'a']) {
				return false;
			}
			curr = curr->children[c - 'a'];
		}

		return true;
	}
};