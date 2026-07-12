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
    int height(TreeNode* root, bool &flag){
        if(root==NULL) return -1;
        int leftHeight = height(root->left, flag);
        int rightHeight = height(root->right, flag);
        if(abs(leftHeight-rightHeight)>1) flag = false;
        return 1+max(leftHeight, rightHeight);
    }    
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        height(root, flag);
        return flag;
    }
};
