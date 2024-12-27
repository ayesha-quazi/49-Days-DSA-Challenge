// Binary Tree Right Side View

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
    //modifed pre order traversal
    void preOrder(TreeNode* root, int level, vector<int>& result) {
        if(!root)
            return;
        
        if(result.size() < level)
            result.push_back(root->val);
        
        preOrder(root->right, level+1, result);
        preOrder(root->left, level+1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> result;
        
        preOrder(root, 1, result);
        
        return result;
    }
};
