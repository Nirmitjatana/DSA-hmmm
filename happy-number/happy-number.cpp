class Solution {
public:
    bool isHappy(int n)
    {
        bool res;
        vector<int> tmpp = {};
        while(true)
        {
            if(n == 1)
            {
                res = true;
                break;
            }
            else
            {
                int tmp = 0;
                while(n>=1)
                {
                    tmp += pow(n % 10, 2);
                    n = n / 10;
                }
                if(find(begin(tmpp),end(tmpp),tmp) != end(tmpp))
                {
                    res = false;
                    break;
                }
                else
                {
                    tmpp.push_back(tmp);
                    n = tmp;
                }
            }
        }  
        return res;
    }
};