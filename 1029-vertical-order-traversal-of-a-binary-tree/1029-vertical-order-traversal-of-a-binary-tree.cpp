/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

       map<int, map<int, multiset<int>>> nodes;

    queue<tuple<TreeNode*, int, int>> q; // node, col, row
    q.push({root, 0, 0});

    while (!q.empty()) {
        auto [node, col, row] = q.front();
        q.pop();

        nodes[col][row].insert(node->val);

        if (node->left)
            q.push({node->left, col - 1, row + 1});
        if (node->right)
            q.push({node->right, col + 1, row + 1});
    }

    vector<vector<int>> ans;
    for (auto &[col, rows] : nodes) {
        vector<int> colVals;
        for (auto &[row, vals] : rows) {
            colVals.insert(colVals.end(), vals.begin(), vals.end());
        }
        ans.push_back(colVals);
    }
    return ans;
    }
};