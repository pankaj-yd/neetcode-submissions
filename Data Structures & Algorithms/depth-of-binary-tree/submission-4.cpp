class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode *, int>> s;
        
        s.push({root, 0});
     

        int ans = 0;

        while( !s.empty()){
            pair<TreeNode*, int> curr = s.top();
            s.pop();

            if(curr.first != nullptr){
                ans = max(ans, curr.second + 1);
                s.push({curr.first->left, curr.second + 1});
                s.push({curr.first->right, curr.second + 1});
            }
        }

        return ans;
    }
};
