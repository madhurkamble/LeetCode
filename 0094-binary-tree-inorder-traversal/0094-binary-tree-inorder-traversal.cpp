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
    vector<int>inorderTraversal(TreeNode*root){
        vector<int>ans;
        TreeNode*current=root;

        while(current!=NULL){
            if(current->left==NULL){
                ans.push_back(current->val);
                current=current->right;
            }
            else{
                TreeNode*IP=current->left;
                while(IP->right!=NULL && IP->right!=current){
                    IP=IP->right;
                }

                if(IP->right==NULL){
                    IP->right=current;
                    current=current->left;
                }
                else{
                    IP->right=NULL;
                    ans.push_back(current->val);
                    current=current->right;
                }
            }
        }
        return ans;
    }
};