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
    int goodnodes(TreeNode *root, int maxVal){
        if(root == nullptr){
            return 0;
        }
        maxVal = max(root->val, maxVal);

        int leftGoodNodes = goodnodes(root->left, maxVal);
        int rightGoodNodes = goodnodes(root->right, maxVal);

        if(maxVal <= root->val){
            return 1 + leftGoodNodes + rightGoodNodes;
        }
        return leftGoodNodes + rightGoodNodes;
    }
public:
    int goodNodes(TreeNode* root) {
        return goodnodes(root, root->val);
    }
};
