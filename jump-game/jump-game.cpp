// class Solution {
// public:
//     bool helper(int idx, vector<int>& nums,vector <int> dp){
//         if(idx == nums.size()-1){
//             return true;
//         }
//         if(dp[idx]!=-1){
//             return dp[idx];
//         }
//         int reach = idx + nums[idx];
//         for( int i=idx+1;i<=reach;i++){
//             if(helper(i,nums,dp)){
//                 return dp[idx] = true;
//             }
//         }
//         return dp[idx] = false;
//     }
//     bool canJump(vector<int>& nums) {
//         vector<int> dp(nums.size(),-1);
//         return helper(0,nums,dp);
//     }
// };   

// class Solution {
//     vector<int> memo;
// public:
//     bool canJump(vector<int>& nums) { 
//         memo.assign(nums.size(),-1);
//         return solve(0,nums);
//     }
//     bool solve(int i,vector<int> nums){
//         if(i==nums.size()-1) return true;
//         if(memo[i]!=-1) return memo[i];
//         int reachable=i+nums[i];
//         for(int k=i+1;k<=reachable;k++){
//             if(solve(k,nums)){
//                 return memo[i]=true;
//             }   
//         }
//         return memo[i]=false;
//     }
// };

// 19 Aug 2021
//recursive
// class Solution {
// public:
//     bool canJump(vector<int>& nums, int i=0) {
//         if(i == nums.size()-1) return 1;
//         int reach = i+nums[i];
//         cout << reach << endl;
//         for(int k=i+1;k<=reach;k++){
//             return canJump(nums,k);
//         }
//         return 0;    
//     }
// };

// DP


class Solution {
public:
    int dp[10005];
    bool solve(vector<int>& nums, int n, int idx){
        if(idx==n-1) return true;
        if(idx>=n) return false;
        if(!dp[idx]) return dp[idx];
        for(int i=1;i<=nums[idx];i++){
            if(solve(nums,n,idx+i)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,n,0);
    }
};
// class Solution {
//     vector<int> memo;
// public:
//     bool canJump(vector<int>& nums) { 
//         memo.assign(nums.size(),-1);
//         bool ret = solve(0,nums);
//         for(int i=0;i<nums.size();i++) cout << memo[i];
//         return ret;
//     }
//     bool solve(int i,vector<int> nums){
//         if(i == nums.size()-1){
//             return true;  
//         }
//         if(memo[i]!=-1) return memo[i];
//         int reach = i+nums[i];
//         for(int k=i+1;k<=reach;k++){
//             if(nums[k] == 0){
//                 return memo[k] = false;
//             }
//             else{
//                 return memo[k] = solve(k,nums);
//             }
//         }
//         return false;
//     }
// };