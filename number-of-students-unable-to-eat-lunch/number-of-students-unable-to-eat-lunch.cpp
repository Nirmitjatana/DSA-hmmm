class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sw) {
        queue<int> q;
        stack<int> s;
        
        for(int i=sw.size()-1;i>-1;i--){
            s.push(sw[i]);
        }
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int count = 0;
        int n = students.size();
        while(true) {
            if(q.empty() || count > 5*n) break;
            if(s.top() == q.front()){
                s.pop();
                q.pop();
            }
            else{
                int back = q.front();
                q.pop();
                q.push(back);
            }
            count++;
        }
        return q.size();
        
        
        
        
        
        // int n = students.size();
        // for(int i=0; i<n; i++) {
        //     q.push(students[i]);
        // }
        // int i=0;
        // int count = 0;
        // while(true) {
        //     if(q.empty() || count > 5*n) break;
        //     if(q.front() == sw[i]) {
        //         q.pop();
        //         sw.erase(sw.begin());
        //     } else {
        //         int x = q.front();
        //         q.pop();
        //         q.push(x);
        //     }
        //     count++;
        // }
        // return q.size();
    }
};