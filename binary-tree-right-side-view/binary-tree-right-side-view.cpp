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
    void helper(vector<int> &ans, TreeNode* root, int &maxlevel, int level){
        
        if(root == NULL) return;
        
        if(level > maxlevel){
            ans.push_back(root->val);
            maxlevel = level;
        }
        helper(ans,root->right,maxlevel,level+1);
        helper(ans,root->left,maxlevel,level+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int max = -1;
        helper(ans,root,max,0);
        return ans;
    }
};