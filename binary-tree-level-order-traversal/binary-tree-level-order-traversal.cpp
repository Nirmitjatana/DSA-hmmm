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
// class Solution {
//     // vector<int> level;
// public:
//     int heightTree(TreeNode* root){
//         if(root==NULL) return 0;
//         int ltree = heightTree(root->left);
//         int rtree = heightTree(root->right);
//         return max(ltree,rtree)+1;
//     }
//     void kthlevel(TreeNode* root, int k, vector<int> &level){
//         if(root == NULL) return;
//         if(k==1){
//             level.push_back(root->val);
//             return;
//         }
//         kthlevel(root->left,k-1,level);
//         kthlevel(root->right,k-1,level);
//         // return;
//     }
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         int H = heightTree(root);
//         for(int i=1;i<=H;i++){
//             kthlevel(root,i-1,level);
//             ans.push_back(level);
//             level.clear();
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q; q.push(root);
        
        while (!q.empty()) {
            vector<int> vec;
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                root = q.front();
                q.pop();
                vec.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};