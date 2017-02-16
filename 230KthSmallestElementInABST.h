//  LeetCode
//
//  Created by Hongyan on 02/13/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

// class Solution {
// public:
// 	int kthSmallest(TreeNode* root, int k) {
// 		TreeNode* curr = root;
// 		TreeNode* prev = NULL;
// 		int count = 0;
// 		while(curr) {
// 			if(!curr->left) {
// 				count++;
// 				if(count == k) {
// 					return curr->val;
// 				}
// 				curr = curr->right;
// 			} else {
// 				prev = curr->left;
// 				while(prev->right && prev->right != curr) {
// 					prev = prev->right;
// 				}

// 				if(!prev->right) {
// 					prev->right = curr;
// 					curr = curr->left;
// 				} else {
// 					prev->right = NULL;
// 					count++;
// 					if(count == k) {
// 						return curr->val;
// 					}
// 					curr = curr->right;
// 				}
// 			}
// 		}
// 		return INT_MIN;
// 	}
// };

struct TreeNodeWithCount {
	int val;
	int count;
	TreeNodeWithCount* left;
	TreeNodeWithCount* right;
	TreeNodeWithCount() {
		val = 0;
		count = 1;
	}
	TreeNodeWithCount(int v) {
		val = v;
		count = 1;
	}
};

TreeNodeWithCount* buildTreeNodeWithCount(TreeNode* root) {
	if(!root) return NULL;
	TreeNodeWithCount* newRoot = new TreeNodeWithCount(root->val);
	newRoot->left = buildTreeNodeWithCount(root->left);
	newRoot->right = buildTreeNodeWithCount(root->right);
	if(newRoot->left) {
		newRoot->count += newRoot->left->count;
	}
	if(newRoot->right) {
		newRoot->count += newRoot->right->count;
	}
	return newRoot;
}

int kthSmallest(TreeNode* root, int k) {
	TreeNodeWithCount* newRoot = buildTreeNodeWithCount(root);
	return kthSmallest(newRoot, k);
}

int kthSmallest(TreeNodeWithCount* root, int k) {
	if(k <= 0 || k > root->count || !root) return -1;
	if(!root->left) {
		if(k == 1) return root->val;
		return kthSmallest(root->right, k - 1);
	} else {
		if(root->left->count == k-1) return root->val;
		if(root->left->count >= k) return kthSmallest(root->left, k);
		return kthSmallest(root->right, k - 1 - root->left->count);
	}
}