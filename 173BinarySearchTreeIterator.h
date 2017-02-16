class BSTIterator {
private: 
    stack<TreeNode *> mystack;
    void put_all_left(TreeNode *root) {
        while(root) {
            mystack.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        put_all_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mystack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* curr = mystack.top();
        mystack.pop();
        if(curr->right) {
            put_all_left(curr->right);
        }
        return curr->val;
    }
};