class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> um;
        for(int i=0;i<nums.size();i++){
            if(um.count(nums[i])){
                return true;
            }
            else{
                um[nums[i]] = true;
            }
        }
        return false;
    }
};