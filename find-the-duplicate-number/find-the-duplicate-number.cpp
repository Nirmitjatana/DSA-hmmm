class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool> um;
        for(int i=0;i<nums.size();i++){
            if(um.count(nums[i])){
                return nums[i];
            }
            else{
                um[nums[i]] = true;
            }
        }
        return -1;
            
    }
};