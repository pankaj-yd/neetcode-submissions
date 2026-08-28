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
    bool areEqual(TreeNode *p, TreeNode *q){
        if( !p && !q){
            return true;
        } else if ( !p || !q){
            return false;
        } else {
            return p->val == q->val && areEqual(p->left, q->left) && areEqual(p->right, q->right); 
        }
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr){
            return true;
        } else if(root == nullptr){
            return false;
        }

        if(root->val == subRoot->val){
            bool isAns = areEqual(root, subRoot);
            if(isAns){
                return isAns;
            }
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
