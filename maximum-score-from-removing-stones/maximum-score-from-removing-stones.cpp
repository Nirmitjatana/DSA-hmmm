class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score = 0;
        priority_queue<int> max;
        max.push(a);
        max.push(b);
        max.push(c);
        while(max.size() >= 2){
            int x = max.top();
            max.pop();
            int y = max.top();
            max.pop();
            x--;
            y--;
            score++;
            if(x > 0) max.push(x);
            if(y > 0) max.push(y);
        }
        
        return score;
    }
};
// 2 4 6
// 1 0 1    4

// 0 3 3  7
// 0 7 8  8
// 4 5 0  7
