class Solution {
private:


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0){
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);

        int nodesLeftSubtree = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        
        vector<int> leftIn(inorder.begin(), inorder.begin() + nodesLeftSubtree);
        vector<int> rightIn(inorder.begin() + nodesLeftSubtree + 1, inorder.end());

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + nodesLeftSubtree);
        vector<int> rightPre(preorder.begin() + 1 + nodesLeftSubtree, preorder.end());
        
        root->left = buildTree( leftPre, leftIn);
        root->right = buildTree( rightPre, rightIn);

        return root;
        
    }
};
