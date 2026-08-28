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
    int ans;
    void preOrderTraversal(TreeNode *root, int &k){
        if(root == nullptr){return;}

        preOrderTraversal(root->left, k);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        
        preOrderTraversal(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k){
        ans = 0;
        preOrderTraversal(root, k);
        return ans;
    }
};
