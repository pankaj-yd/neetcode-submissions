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
    void preTraverse(TreeNode *node, vector<int> &tree){
        if(node == nullptr){
            return;
        }
        preTraverse(node->left, tree);
        int n = tree.size();
        if( n > 0 && tree[n - 1] > node->val){
            tree.push_back(node->val);
            return;
        }
        tree.push_back(node->val);
        preTraverse(node->right, tree);
    }

public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        vector<int> tree;
        preTraverse(root, tree);

        int n = tree.size();
        for(int i = 1; i < n; i++){
            if(tree[i] <= tree[i-1]){
                return false;
            }
        }
        return true;
    }
};
