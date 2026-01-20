#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()) {
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();

            if(t1 == NULL && t2 == NULL)
                continue;

            if(t1 == NULL || t2 == NULL)
                return false;

            if(t1->val != t2->val)
                return false;

            // mirror order
            q.push(t1->left);
            q.push(t2->right);

            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};

int main() {
    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;
    if(obj.isSymmetric(root))
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is NOT Symmetric" << endl;

    return 0;
}
