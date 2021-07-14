class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sw) {
        queue<int> q;
        int n = students.size();
        for(int i=0; i<n; i++) {
            q.push(students[i]);
        }
        int i=0;
        int count = 0;
        while(true) {
            if(q.empty() || count > 5*n) break;
            if(q.front() == sw[i]) {
                q.pop();
                sw.erase(sw.begin());
            } else {
                int x = q.front();
                q.pop();
                q.push(x);
            }
            count++;
        }
        return q.size();
    }
};