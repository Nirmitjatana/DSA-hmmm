// class Solution {
// public:
//     int getMinPath(vector <vector <int>> &grid, int i, int j, vector <vector<int>> &dp) {
//         if (i == 0 && j == 0) {
//             return grid[i][j];
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
        
//         int m = INT_MAX;
//         if (j > 0) {
//             m = grid[i][j] + getMinPath(grid, i, j - 1, dp);
//         }
//         if (i > 0) {
//             int s = grid[i][j] + getMinPath(grid, i - 1, j, dp);
//             m = min(m, s);
//         }
        
//         dp[i][j] = m;
//         return dp[i][j];
//     }
    
    
//     int minS(vector<vector<int>>& grid,int i,int j,int m,int n, vector<vector<int>> &dp){
//         //base case
//         if(i == m && j ==n){
//             return grid[i][j];
//         }
//         //look up
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
        
//         //recursive case
//         int rightSum,downSum;
//         int ans=0;
//         rightSum = downSum = INT_MAX;
//         if(i<m) rightSum = grid[i][j]+minS(grid,i+1,j,m,n,dp);
//         if(j<n) downSum = grid[i][j]+minS(grid,i,j+1,m,n,dp);
//         ans = min(rightSum,downSum);
//         return dp[i][j] = ans;
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size()-1;
//         int n = grid[0].size()-1;
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         return minS(grid,0,0,m,n,dp);
//     }
    
    class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>v(n,vector<int>(m,-1));
        return fun(0,0,n,m,a,v);
    }
    
    int fun(int i,int j, int n, int m,vector<vector<int>>& a,vector<vector<int>>& v)
    {
        if(i>n-1||j>m-1)
        {
            return INT_MAX;
        }
        else if((i==n-1)&&(j==m-1))
        {
            return a[i][j];
        }
        else if(v[i][j] != -1)
        {
            return v[i][j];
        }
        return v[i][j] = a[i][j] + min(fun(i+1,j,n,m,a,v),fun(i,j+1,n,m,a,v));
    }
};
    
    
    
    
    
// };