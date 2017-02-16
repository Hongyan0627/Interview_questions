	//  LeetCode
//
//  Created by Hongyan on 02/05/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		unordered_map<int,int> mymap;
		int maxCount = 0;
		vector<int> res;
		if(!root) return res;
		TreeNode* curr = root;
		while(curr) {
			if(!curr->left) {
				mymap[curr->val]++;
				if(mymap[curr->val] > maxCount) {
					maxCount = mymap[curr->val];
				}
				curr = curr->right;
			} else {
				TreeNode* prev = curr->left;
				while(prev->right && prev->right != curr) {
					prev = prev->right;
				}

				if(!prev->right) {
					prev->right = curr;
					curr = curr->left;
				} else {
					prev->right = NULL;
					mymap[curr->val]++;
					if(mymap[curr->val] > maxCount) {
					    maxCount = mymap[curr->val];
				    }
				    curr = curr->right;
				}
			}
		}

		for(auto it = mymap.begin(); it != mymap.end(); it++) {
			if(it->second == maxCount) {
				res.push_back(it->first);
			}
		}
		return res;
	}
};