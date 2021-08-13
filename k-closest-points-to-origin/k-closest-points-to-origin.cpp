class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int i=0;i<points.size();i++)
        {
            pq.push({(points[i][0]*points[i][0]) + (points[i][1]*points[i][1]),i});
        }
        while(!pq.empty() and k)
        {
            auto topElement = pq.top();
            pq.pop();
            ans.push_back(points[topElement.second]);
            k--;
        }
        return ans;
    }
};