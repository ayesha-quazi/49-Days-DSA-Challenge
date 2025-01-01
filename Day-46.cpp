// Vertical Order Traversal of a Binary Tree


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
        // {column -> {row -> multiset of values}}
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {column, row}}
        
        q.push({root, {0, 0}});
        
        // BFS traversal
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            
            int col = pos.first, row = pos.second;
            nodes[col][row].insert(node->val);
            
            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }
        
        // Prepare the result
        vector<vector<int>> ans;
        for (auto& [col, colMap] : nodes) {
            vector<int> colValues;
            for (auto& [row, values] : colMap) {
                colValues.insert(colValues.end(), values.begin(), values.end());
            }
            ans.push_back(colValues);
        }
        
        return ans;
    }
};
