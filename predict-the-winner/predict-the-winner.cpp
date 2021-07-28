// class Solution {
// public:
//     int awins(vector<int> v,int l, int r){
//         return max(v[l]+awins(v,l+1,r),v[r]+awins(v,l,r-1));
//     }
    
//     bool PredictTheWinner(vector<int>& nums) {
//         if(awins(nums,0,nums.size()-1) >=0 ) return true;
//         return false;
//     }
// };

class Solution {
public:
        // int dp[21][21];
        int solve(vector<int>& v,int l,int r){
            if(l>r) return 0;
            // if(dp[l][r]!=-1) return dp[l][r];
            // return  dp[l][r] = max(v[l]-solve(v,l+1,r),v[r]-solve(v,l,r-1));
            return max(v[l]-solve(v,l+1,r),v[r]-solve(v,l,r-1));
        }
    bool PredictTheWinner(vector<int>& v) {
        // memset(dp,-1,sizeof(dp));
        
        int n=v.size();
		// int sum=0;
		// for(int i;i<n;i++) sum+=v[i];
        // bool val=true;
        if(solve(v,0,n-1)>=0) return true;
        return false;
    }
};