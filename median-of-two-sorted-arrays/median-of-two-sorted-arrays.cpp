class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        priority_queue<int> pq;
        int m = nums1.size();
        int n = nums2.size();
        for(auto m1 : nums1){
            pq.push(m1);
        }
        for(auto n1 : nums2){
            pq.push(n1);
        }
        if((m+n)%2!=0){
            for(int i=0;i<(m+n)/2;i++){
                pq.pop();
            }
            ans = pq.top();
        }
        else{
            for(int i=0;i<((m+n)/2)-1;i++){
                pq.pop();
            }
            double a = pq.top();
            pq.pop();
            double b = pq.top();
            ans = (a+b)/2;
        }
        return ans;
        
    }
};