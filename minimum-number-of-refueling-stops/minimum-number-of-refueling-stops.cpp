class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int pos = startFuel;
        priority_queue<int> pq;
        // int fuel = ;
        int ans = 0;
        int N = stations.size();
        int i=0;
        while(pos < target){
            while(i < N and pos >= stations[i][0]){
                pq.push(stations[i++][1]);
            }
            if(pq.empty()){
                return -1;
            }
            pos+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};