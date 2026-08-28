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
    pair<int,int> maxPath(TreeNode* root) {
        if(root == nullptr){
            return {-1001, -1001};
        }

        pair<int,int> leftSum = maxPath(root->left);
        pair<int,int> rightSum = maxPath(root->right);

        pair<int,int> returnSum;
        returnSum.first = max(max(max(leftSum.first, rightSum.first) ,leftSum.second + root->val + rightSum.second), root->val);
        returnSum.second = max(max(leftSum.second + root->val, rightSum.second + root->val), root->val);
        cout << returnSum.first << " " << returnSum.second << "\n";
        return returnSum;
    }
public:
    int maxPathSum(TreeNode* root) {
        pair<int,int> ans = maxPath(root);

        return max(ans.first, ans.second);
    }
};
