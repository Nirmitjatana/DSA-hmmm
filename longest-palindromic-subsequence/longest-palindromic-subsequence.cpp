class Solution {
public:
    int lcs(string text1, string text2) {
        // bottom up
        int x = text1.length();
        int y = text2.length();
        int dp[x+1][y+1];
        memset(dp,-1,sizeof(dp));    
        for(int i=0;i<=x;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<=y;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return lcs(s,s2);
    }
};