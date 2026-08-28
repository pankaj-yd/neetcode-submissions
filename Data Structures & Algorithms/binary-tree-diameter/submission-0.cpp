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
    pair<int,int> depthDia(TreeNode* root){
        if(root == nullptr){
            return {0, 0};
        }
        pair<int, int> left = depthDia(root->left);
        pair<int, int> right = depthDia(root->right);

        int maxDepth = 1 + max(left.first, right.first);

        int maxDia = max(left.second, right.second);
        maxDia = max(maxDia, left.first + right.first);

        return {maxDepth, maxDia};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return depthDia(root).second;
        
    }
};
