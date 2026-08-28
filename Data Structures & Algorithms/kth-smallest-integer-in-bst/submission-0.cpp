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
    void preOrderTraversal(TreeNode *node, vector<int> &tree, int k){
        if(tree.size() == k){
            return;
        }
        if( ! node ){
            return;
        }
        preOrderTraversal(node->left, tree, k);
        tree.push_back(node->val);
        preOrderTraversal(node->right, tree, k);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tree;
        preOrderTraversal(root, tree, k);

        return tree[k-1];
    }
};
