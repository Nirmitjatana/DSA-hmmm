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
    void preorder(TreeNode* p, TreeNode* q, bool &ans){
        if(p == NULL && q == NULL){
            return;
        }
        if((p == NULL && q!= NULL) || (p != NULL && q == NULL)){
            ans = false;
            return;
        }
        if(p->val != q->val){
            ans = false;
        }
        cout << p->val << " " << q->val << endl;
        preorder(p->left,q->left,ans);
        preorder(p->right,q->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        preorder(p,q,ans);
        return ans;
    }
};