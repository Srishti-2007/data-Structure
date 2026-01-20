#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void find(TreeNode* root, int pos, int &l, int &r) {
        if (!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<int> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);

        queue<TreeNode*> q;
        queue<int> index;
        q.push(root);
        index.push(0);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            if (pos >= 0)
                positive[pos].push_back(temp->val);
            else
                negative[abs(pos)].push_back(temp->val);

            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }
            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        // --- Final Loop to fill 1D vector ---
        vector<int> ans;

        // 1. Negative columns (Left to Right: e.g., index 2, then index 1)
        for (int i = negative.size() - 1; i >= 1; i--) {
            for (int j = 0; j < negative[i].size(); j++) {
                ans.push_back(negative[i][j]);
            }
        }

        // 2. Positive columns (Left to Right: index 0, 1, 2...)
        for (int i = 0; i < positive.size(); i++) {
            for (int j = 0; j < positive[i].size(); j++) {
                ans.push_back(positive[i][j]);
            }
        }

        return ans;
    }
};

int main() {
    // Tree build: [1, 2, 3, 4, 6, 5, 7]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<int> result = sol.verticalTraversal(root);

    cout << "Vertical Order (1D Vector): ";
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}