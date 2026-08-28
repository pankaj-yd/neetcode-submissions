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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "";
        }

        string s = "";

        queue<TreeNode *> q;
        q.push(root);

        while( !q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode *node = q.front();
                q.pop();
                if(node == nullptr){
                    s += "-1001#";
                } else {
                    s += to_string(node->val) + "#";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return nullptr;
        }
        int i = 0;
        int n = data.size();

        queue<TreeNode *> q;
        int val = getVal(data, i);

        TreeNode *root = new TreeNode(val);
        q.push(root);
        while(i < n){
            int m = q.size();
            if(m == 0){
                break;
            }
            for(int k = 0; k < m; k++){
                TreeNode *node = q.front();
                q.pop();
                
                int left = getVal(data, i);
                int right = getVal(data, i);

                if(left != -1001){
                    TreeNode *leftNode = new TreeNode(left);
                    node->left = leftNode;
                    q.push(leftNode);
                }
                if(right != -1001){
                    TreeNode *rightNode = new TreeNode(right);
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        return root;
    }

private:
    int getVal(string &s, int &i){
        int j = i;
        while(s[j] != '#'){
            j++;
        }
        int val = stoi(s.substr(i, i+j));
        
        i = j+1;
        return val;
    }
};















