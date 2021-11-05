class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        memset(dp,-1,sizeof(dp));
        //initialization
        for(int i=0;i<=amount;i++) dp[0][i] = INT_MAX - 1;
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=1;i<=amount;i++){
            if(i % coins[0] == 0){
                dp[1][i] = i/coins[0];
            }
            else{
                dp[1][i] = INT_MAX - 1;    
            }
            
        }
        //logic
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount] >= INT_MAX - 1 ? -1: dp[n][amount];
        
    }
};