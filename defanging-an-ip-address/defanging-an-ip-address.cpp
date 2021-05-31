class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        string fn = "[.]";
        int len = address.length();
        for(int i=0;i<len;i++){
            // cout << x;
            if(address[i] != '.'){
                ans = ans + address[i];
            }
            else{
                ans.append(fn);
            }
        }
        return ans;
    }
};