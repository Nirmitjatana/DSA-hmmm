class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
      while (tx > 0 && ty > 0) {
        if (tx < sx || ty < sy) return false;
        if (tx == sx && ty == sy) return true;
        if (tx > ty) tx -= ty*(max(1, (tx-sx)/ty));
        else ty -= tx*(max(1, (ty-sy)/tx));
      }
      return false;
    }
};