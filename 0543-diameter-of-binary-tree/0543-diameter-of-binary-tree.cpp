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

    int height(TreeNode*root){
        if(root==NULL) return 0;
        int left_ht=height(root->left);
        int right_ht=height(root->right);
        return max(left_ht,right_ht)+1;     
        }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL) return 0;
        int left_diameterOfBinaryTree = diameterOfBinaryTree(root->left);
        int right_diameterOfBinaryTree = diameterOfBinaryTree(root->right);
        int curr_diameterOfBinaryTree = height(root->left) + height(root->right);
        return max(curr_diameterOfBinaryTree,max(left_diameterOfBinaryTree,right_diameterOfBinaryTree));
    }
};