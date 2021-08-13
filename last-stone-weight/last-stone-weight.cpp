class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto st: stones){
            pq.push(st);
        }
        while(pq.size()>=2){
            //logic
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            cout << x << " " << y << endl;
            if(x != y){
                pq.push(x-y);
            }
        }
        if(pq.size()==0){
            return 0;
        }
        else{
            return pq.top();
        }
    }
};