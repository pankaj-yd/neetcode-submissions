class Solution {
private:


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int n = preorder.size();
        if(n == 0){
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);
        int i = 0, j = 0;
        
        while(i < n && inorder[i] != preorder[0]){
            i++;
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + i + 1);

        root->left = buildTree(leftPreorder, leftInorder);

        vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());
        vector<int> rightPreorder(preorder.begin() + 1 + i, preorder.end());
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};
