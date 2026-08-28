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
private:
    bool isValid(TreeNode *root, int leftMax, int rightMin){
        if(root == nullptr){
            return true;
        }

        if(root->val > leftMax && root->val < rightMin){
            return isValid(root->left, leftMax, root->val) 
            && isValid(root->right, root->val, rightMin);
        }

        return false;
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};
