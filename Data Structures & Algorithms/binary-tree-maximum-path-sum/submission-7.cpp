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
    vector<int> getsums(TreeNode *node){
        if(node == nullptr){
            return {INT_MIN, INT_MIN};
        }
        vector<int> left = getsums(node->left);
        vector<int> right = getsums(node->right);
        int maxSum = node->val;
        if(left[0] > right[0]){
            if(left[0] != INT_MIN){
                maxSum += left[0];
            }
        } else {
            if(right[0] != INT_MIN){
                maxSum += right[0];
            }
        }

        maxSum = max(maxSum, node->val);

        int maxSubsum = node->val;
        if(left[0] != INT_MIN){
            maxSubsum += left[0];
        }
        if(right[0] != INT_MIN){
            maxSubsum += right[0];
        }
    
        maxSubsum = max(maxSubsum, max(left[1], right[1]));
        maxSubsum = max(maxSubsum, node->val);
        // cout << maxSum << " " << maxSubsum << endl;
        return {maxSum, maxSubsum};
    }
public:
    int maxPathSum(TreeNode* root){
        vector<int> res;
        res = getsums(root);
        return max(res[0], res[1]);
    }
};
