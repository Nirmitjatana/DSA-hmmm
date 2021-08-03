// int dp[501][501];
// int maxSatisfaction(vector<int>& s) {
//     int n=s.size();
//     sort(s.begin(),s.end());
//     memset(dp,-1,sizeof dp);
//     return solve(s,0,1,n); 
// }
// int solve(vector<int>&s,int st,int time,int end)
// {
//     if(st==end-1)
//     return time*s[st];
//     if(st>end)
//         return 0;
//     if(dp[st][time]!=-1)
//         return dp[st][time];
//     int ans1=time * s[st]+solve(s,st+1,time+1,end);
//     int ans2=solve(s,st+1,time,end);
//     return dp[st][time]=max(0,max(ans1,ans2));
// }

class Solution {
public:
    int helper(vector<int> &s, int st, int end, int time, vector<vector<int>> &dp){
        if(st == end){
            return time*s[st];
        }
        if(st > end){
            return 0;
        }
        if(dp[st][time] != -1){
            return dp[st][time];
        }
        int ans1 = time*s[st] + helper(s,st+1,end,time+1,dp);
        int ans2 = helper(s,st+1,end,time,dp);
        return dp[st][time] = max(0,max(ans1,ans2));
    }
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(),s.end());
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return helper(s,0,n-1,1,dp);
    }
};