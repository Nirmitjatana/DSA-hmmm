class Solution {
public:
    int dp[2501][2501];
    int lcs(vector<int>& nums, vector<int>& n1, int i, int j){
        if(i == nums.size() || j == n1.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(nums[i] == n1[j]){
            return dp[i][j] = 1 + lcs(nums,n1,i+1,j+1);
        }
        else{
            return dp[i][j] = max(lcs(nums,n1,i+1,j),lcs(nums,n1,i,j+1));
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> n1;
        for(int i=0;i<nums.size();i++){
            n1.push_back(nums[i]);
        }
        sort(n1.begin(),n1.end());
        vector<int> n2;
        n2.push_back(n1[0]);
        for(int i=1;i<n1.size();i++){
            if(n1[i-1] != n1[i]){
                n2.push_back(n1[i]);
            }
        }
        memset(dp,-1,sizeof(dp));
        return lcs(nums,n2,0,0);
    }
};