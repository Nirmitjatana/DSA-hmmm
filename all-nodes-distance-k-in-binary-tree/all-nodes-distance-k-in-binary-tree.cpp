class Solution {
public:
    vector<TreeNode* > path;
    bool find(TreeNode* root, int tar){
        if(root==NULL)
            return false;
        if(root->val== tar){
            path.push_back(root);
            return true;
        }
        if(find(root->left, tar)){
            path.push_back(root);
            return true;
        }
        if(find(root->right, tar)){
            path.push_back(root);
            return true;
        }
        return false;            
    }
    
    vector<int> res;
    void down(TreeNode* root, int k, TreeNode* block){
        if(k==0 && root!=NULL){
            res.push_back(root->val);
            return;
        }
        if(root==NULL){
            return;
        }
        if(root->left!=block)
            down(root->left, k-1, block);
        if(root->right!=block)
            down(root->right, k-1, block);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find(root, target->val);
        down(path[0], k, path[0]);
        for(int i=1; i<path.size() ;i++){
            down(path[i], k-i, path[i-1]);
        }
        return res;
    }
};