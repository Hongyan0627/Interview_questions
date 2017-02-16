//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	void connect(TreeLinkNode *root)  {
		if(!root) return;
		TreeLinkNode* curr = root;
		TreeLinkNode* head = NULL;
		TreeLinkNode* prev = NULL;
		while(curr) {
			while(curr) {
				if(curr->left) {
					if(prev) {
						prev->next = curr->left;
					} else {
						head = curr->left;
					}
					prev = curr->left;
				}

				if(curr->right) {
					if(prev) {
						prev->next = curr->right;
					} else {
						head = curr->right;
					}
					prev = curr->right;
				}
				curr = curr->next;
			}
			curr = head;
			prev = NULL;
			head = NULL;
		}
	}
};