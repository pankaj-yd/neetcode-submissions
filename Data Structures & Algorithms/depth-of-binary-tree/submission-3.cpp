class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        stack<pair<TreeNode *, int>> s;
        
        s.push({root, 1});
     

        int ans = 1;

        while( !s.empty()){
            pair<TreeNode*, int> curr = s.top();
            s.pop();

            if(curr.first->left){
                ans = max(ans, curr.second + 1);
                s.push({curr.first->left, curr.second + 1});
            }
            if(curr.first->right){
                ans = max(ans, curr.second + 1);
                s.push({curr.first->right, curr.second + 1});
            }
        }

        return ans;
    }
};
