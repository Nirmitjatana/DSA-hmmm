class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        if(n==0) return -1;
        for(int i=1;i<n+1;i++){
            q.push(i);
        }
        while(q.size() > 1){
            for(int i=1;i<k;i++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front() ? q.front() : -1;
    }
};