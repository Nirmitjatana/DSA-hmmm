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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> first;
        // first.push_back(root->val);
        // ans.push_back(first);
        // first.clear();
        TreeNode* f;
        while(q.size()>1){
            f = q.front();
            q.pop();
            if(f == NULL){
                ans.push_back(first);
                first.clear();
                // cout << endl;
                q.push(NULL);
            }
            else{
                first.push_back(f->val);
                // cout << f->val;
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        if(!first.empty()){
            ans.push_back(first);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};