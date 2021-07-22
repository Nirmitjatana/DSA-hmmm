class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        for(int i=0;i<size;i++){
            int addr = nums[i];
            int temp = nums[addr];
            cout << temp;
            ans.push_back(temp);
        }
        // ans.push_back(1);
        return ans;
    }
};