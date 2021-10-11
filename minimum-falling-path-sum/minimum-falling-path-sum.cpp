class Solution {
public:
    int helper(vector<vector<int>>& matrix, int i, int j, int n, vector<vector<int>> &dp){
        // base case
        if(i == n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // rec case
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if(j>0){
            op1 = matrix[i][j-1] + helper(matrix,i+1,j-1,n,dp);
        }
        if(j < n-1){
            op2 = matrix[i][j+1] + helper(matrix,i+1,j+1,n,dp);
        }
        op3 = matrix[i][j] + helper(matrix,i+1,j,n,dp);
        return dp[i][j] = min(min(op1,op2),op3);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int k = 0; k < n; k++){
            int op = matrix[0][k] + helper(matrix,1,k,n,dp);
            ans = min(ans,op);
        }
        return ans;
    }
};