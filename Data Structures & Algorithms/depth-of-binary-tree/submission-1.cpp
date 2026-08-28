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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<pair<TreeNode *, int>> q;
        int level = 0;
        q.push({root, level});
        while( !q.empty() ){
            while(!q.empty() && q.front().second == level){
                pair<TreeNode*, int> p = q.front();
                q.pop();
                if(p.first->left != nullptr){
                    q.push({p.first->left, level + 1});
                }
                if(p.first->right != nullptr){
                    q.push({p.first->right, level + 1});
                }
            }
            level++;
        }

        return level;
    }
};
