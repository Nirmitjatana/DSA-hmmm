// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             if(nums[i]>0){
//                 pq.push(nums[i]);
//             }
//         }
//         int ans = 1;
//         while(!pq.empty()){
//             if(pq.top()==ans){
//                 ans++;
//                 pq.pop();
//             }
//             else{
//                 break;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                s.insert(nums[i]);   
            }
        }
        int ans = 1;
        while(!s.empty()){
            auto itr = s.begin();
            if(*itr==ans){
                s.erase(s.begin());
                ans++;
            }
            else{
                break;
            }
        }
        // return ans;
        return ans;
    }
};