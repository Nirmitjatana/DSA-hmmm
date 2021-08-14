class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            if(um.count(target-nums[i]) && um[target-nums[i]]!=i){
                // cout << target-nums[i];
                ans.push_back(i);
                ans.push_back(um[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};