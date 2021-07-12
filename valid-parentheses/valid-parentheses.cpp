class Solution {
public:
    bool isValid(string s) {
        stack<char> stac;
        int len = s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stac.push(s[i]);
            }
            if (stac.empty()) return false;
            else if(s[i]==')'){
                if(stac.top()=='('){
                    stac.pop();
                }
                else return false;
            }
            else if(s[i]==']'){
                if(stac.top()=='['){
                    stac.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(stac.top()=='{'){
                    stac.pop();
                }
                else return false;
            }
        }
        return stac.empty();
    }
};