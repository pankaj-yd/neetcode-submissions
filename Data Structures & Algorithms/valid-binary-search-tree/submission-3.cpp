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
    bool maxVal(TreeNode *root, int intmin, int intmax){
        if(root == nullptr){
            return true;
        } else if(intmin < root->val && root->val < intmax ){
            return maxVal(root->left, intmin, root->val) && maxVal(root->right, root->val, intmax);
        }
        return false;
        
    }
public:
    bool isValidBST(TreeNode* root) {
        return maxVal(root, -1001, 1001);
    }
};
