#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};


class solution {
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
		if(root->val == key) return root;
		if(root->val < key) return searchNode(root->right, key);
		return searchNode(root->left, key);
	}

	TreeNode* deleteNode(TreeNode* root, int key) {
		if(!searchNode(root,key)) return root;
		TreeNode dummy(0);
		dummy.right = root;

		TreeNode* parent = &dummy;
		TreeNode* curr = root;

		while(curr->val != key) {
			if(curr->val > key) {
				curr
			}
		}
	}
};

int main() {
	return 0;
}

