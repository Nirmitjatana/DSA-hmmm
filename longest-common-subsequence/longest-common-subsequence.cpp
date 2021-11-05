class Solution {
public:
    int dp[1001][1001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int welp(string &text1, string &text2,int i ,int j){
        //base case
        if(i == text1.length() || j==text2.length()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //recursive case
        if(text1[i] == text2[j]){
            return dp[i][j] =  1 + welp(text1,text2,i+1,j+1);
        }
        else{            
            return dp[i][j] = max(welp(text1,text2,i+1,j),welp(text1,text2,i,j+1));
        }
    }
    int longestCommonSubsequence(string &text1, string &text2) {
        return welp(text1,text2,0,0);
    }
};