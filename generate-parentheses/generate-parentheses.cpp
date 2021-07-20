class Solution {
public:
    void add(vector<string> &ans, string s, int idx, int n, int open, int close){
        if(idx == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s.append("(");
            add(ans,s,idx+1,n,open+1,close);
            s.erase(s.length()-1,1);
        }
        if(close < open){
            s.append(")");
            add(ans,s,idx+1,n,open,close+1);
            s.erase(s.length()-1,1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        add(ans,s,0,n,0,0);
        return ans;
    }
};