/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val){
            TreeNode*leftLCA = lowestCommonAncestor(root->left,p,q);
            return leftLCA;
        }
        else if(root->val < p->val && root->val < q->val){
            TreeNode*rightLCA = lowestCommonAncestor(root->right,p,q);
            return rightLCA;
        }
        else{
            return root;
        }
    }
};