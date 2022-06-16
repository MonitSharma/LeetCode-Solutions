class Solution {
public:
    int mySqrt(int x) {
        int y = 1;
        int n = x;
        while (n > y) {
            n = y +  (n - y) / 2;
            y = x / n;
        }
        return n;
    }
};