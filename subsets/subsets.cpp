class Solution {
public:
    void generate(vector<int> nums, vector<vector<int>> &ans, vector<int> sub,int idx){
        if(idx == nums.size()){
            ans.push_back(sub);
            return;
        }
        generate(nums,ans,sub,idx+1);
        sub.push_back(nums[idx]);
        generate(nums,ans,sub,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        generate(nums,ans,sub,0);
        return ans;
    }
};