class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int neg = nums[0];
        bool allN = true;
        dp[0] = nums[0]>0?nums[0]:0;
        int max_so_far = nums[0];
        for( int i=1;i<nums.size();i++){
            if(nums[i] > -1){
                allN = false;
            }
            else{
                neg = max(neg,nums[i]);
            }
            dp[i]=dp[i-1]+nums[i];
            if(dp[i]<0) dp[i]=0;    
            max_so_far = max(dp[i],max_so_far);
        }
        if(allN){
            return neg;
        }
        return max_so_far;
    }
};