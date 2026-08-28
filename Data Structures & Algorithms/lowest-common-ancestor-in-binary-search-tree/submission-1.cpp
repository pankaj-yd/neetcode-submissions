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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<int> pAncestor;

        TreeNode *curr = root;
        while(curr->val != p->val){
            pAncestor.insert(curr->val);
            if(curr->val > p->val){
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        pAncestor.insert(curr->val);
        
        int ans = root->val;
        curr = root;
        while(curr->val != q->val){
            if(pAncestor.find(curr->val) != pAncestor.end()){
                ans = curr->val;
            }

            if(curr->val > q->val){
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if(pAncestor.find(curr->val) != pAncestor.end()){
            ans = curr->val;
        }
        
        curr = root;
        while(curr->val != ans){
            if(curr->val > ans){
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return curr;
    }
};
