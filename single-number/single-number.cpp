class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> um;
        for(int i=0;i<n;i++){
            auto it = um.find(nums[i]);
            if(it!=um.end()){
                um[nums[i]] = true;
            }
            else{
                um[nums[i]] = false;    
            }
        }
        for(auto it = um.begin();it!=um.end();it++){
            if(it->second == false){
                return it->first;
            }
        }
        return -1;
    }
};