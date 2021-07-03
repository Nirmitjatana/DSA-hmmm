// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n==1){
//             return true;
//         }
//         cout << n;
//         if(n%2!=0){
//             return false;
//         }
//         isPowerOfTwo(n/2);
//         return true;
//     }
// };
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        if(n<=0) return false;
        bool res = isPowerOfTwo(n/2);
        return n%2 ==0 && res;
    }
};