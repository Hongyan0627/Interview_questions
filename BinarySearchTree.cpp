#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* buildTree(vector<int>& nums) {
		if(nums.empty()) return NULL;
		TreeNode* root = new TreeNode(nums[0]);
		for(int i = 1; i < nums.size(); i++) {
			addNode(root, nums[i]);
		}
		return root;
	}

	bool addNode(TreeNode* root, int key) {
		if(root->val == key) return false;
		if(root->val < key) {
			if(root->right == NULL) {
				root->right = new TreeNode(key);
				return true;
			} else {
				return addNode(root->right, key);
			}
		} else {
			if(root->left == NULL) {
				root->left = new TreeNode(key);
				return true;
			} else {
				return addNode(root->left, key);
			}
		}
	}

	bool searchNode(TreeNode* root, int key) {
		if(!root) return false;
		if(root->val == key) return true;
		if(root->val < key) return searchNode(root->right, key);
		return searchNode(root->left, key);
	}

	int getMin(TreeNode* node) {
		TreeNode* curr = node;
		while(curr->left) {
			curr = curr->left;
		}
		return curr->val;
	}

	void deleteNode(TreeNode* root, TreeNode* parent, int key) {
		if(!root) return;
		if(root->val < key) {
			deleteNode(root->right, root, key);
		} else if(root->val > key) {
			deleteNode(root->left, root, key);
		} else {
			if(root->left && root->right) {
				root->val = getMin(root->right);
				deleteNode(root->right, root, root->val);
			} else if (parent->left == root) {
				parent->left = (root->left) ? root->left : root->right;
				delete root;
			} else {
				parent->right = (root->left) ? root->left : root->right;
				delete root;
			}
		}
	}

	TreeNode* deleteNode(TreeNode* root, int key) {
		if(!root) return NULL;
		if(root->val == key) {
			TreeNode dummy(0);
			dummy.right = root;
			deleteNode(root, &dummy, key);
		} else {
			deleteNode(root, NULL, key);
		}
	}
};

int main() {
	return 0;
}

