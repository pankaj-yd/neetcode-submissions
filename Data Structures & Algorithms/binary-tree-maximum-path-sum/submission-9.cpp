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
    int maxPath(TreeNode* root, int &ans){
        if(root == nullptr){
            return 0;
        }

        int left = max(maxPath(root->left, ans), 0);
        int right = max(maxPath(root->right, ans), 0);

        ans = max(ans, left + right + root->val);

        return max(left + root->val, right + root->val);
    }
public:
    int maxPathSum(TreeNode* root){
        int ans = root->val;

        maxPath(root, ans);
        return ans;
    }
};
