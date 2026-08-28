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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return vector<vector<int>> ();
        }
        TreeNode *curr = root;
        queue<TreeNode *> q;

        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> v(n, 0);
            for(int i = 0; i < n; i++){
                TreeNode *p= q.front();
                q.pop();
                v[i] = p->val;

                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            ans.push_back(v);
        }
        return ans; 
    }
};
