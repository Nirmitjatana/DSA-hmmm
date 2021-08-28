// ")())))(()(())))(()""
// "))))((())))(()()""


class Solution {
public:
    // int longestValidParentheses(string s) {
//         stack<char> stack;
//         int len = s.length();
//         int count = 0;
//         int ans = 0;
//         for(int i=0;i<len;i++){
//             if(s[i]=='('){
//                 stack.push(s[i]);
//             }
//             else if(s[i]==')'){
//                 if(!stack.empty()){
//                     if(stack.top()=='('){
//                         stack.pop();
//                         count += 2;
//                         if(count > ans){
//                             ans = count;
//                         }
//                     }
//                     else{
//                         count = 0;
//                         stack.push(s[i]);
//                     }
//                 }
//                 // else{
//                 //     stack.push(s[i]);
//                 //     count = 0;
//                 // }
                
//             }
//         }
//         return ans;
// }
        int longestValidParentheses(string s) {
            stack<int> st;
            st.push(-1);
            int res=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='(')st.push(i);
                else{
                    if(!st.empty())st.pop();
                    if(!st.empty())res=max(res,i-st.top());
                    else
                        st.push(i);
                }
            }
            return res;
        }
        
        
        
        
    
};