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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        vector<int> level;
        while(!q.empty()){
        TreeNode*current=q.front();
        q.pop();
        if(current == NULL){

                ans.push_back(level);  
                level.clear();          

                if(!q.empty()){
                    q.push(NULL);
                }
            }
        else{
            level.push_back(current->val);

            if(current->left != NULL){
                q.push(current->left);
            }

            if(current->right!=NULL){
                q.push(current->right);
            }
        }
    
    }
    return ans;

    }
};