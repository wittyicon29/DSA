class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long abs_n = abs((long long)n);

        while (abs_n > 0) {
            if (abs_n & 1) {
                res *= x;
            }
            x *= x;
            abs_n >>= 1;
        }

        return n < 0 ? 1 / res : res;
    }
};
