class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=nums[0];
        vector<int> ans;
        ans.push_back(sum);
        int l = nums.size();
        for(int i=1;i<l;i++){
            sum+=nums[i];
            ans.push_back(sum);
        }
        return ans;
        
    }
};