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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        
        int ltree = height(root->left);
        int rtree = height(root->right);
        
        return max(ltree,rtree)+1;
    }
    void kthlevelodd(TreeNode* root, int k, vector<int> &level){
        if(root==NULL) return;
        
        if(k==1){
            level.push_back(root->val);
            return;
        }
        
        kthlevelodd(root->left,k-1,level);
        kthlevelodd(root->right,k-1,level);
        
    }
    void kthleveleven(TreeNode* root, int k, vector<int> &level){
        if(root==NULL) return;
        
        if(k==1){
            level.push_back(root->val);
            return;
        }

        kthleveleven(root->right,k-1,level);
        kthleveleven(root->left,k-1,level);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        int H = height(root);
        for( int i=1; i<=H; i++){
            if(i%2==0){
                kthleveleven(root,i,level);
                ans.push_back(level);
                level.clear();
            }
            else{
                kthlevelodd(root,i,level);
                ans.push_back(level);
                level.clear();
            }
        }
        return ans;
    }
};