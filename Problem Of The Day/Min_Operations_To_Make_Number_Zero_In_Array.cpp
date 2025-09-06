class Solution {
public:
    
 long long getOps(long long n) {
        if (n <= 0) return 0;
        long long res = 0, ops = 0, powerOfFour = 1;
        while (powerOfFour <= n) {
            long long l = powerOfFour;
            long long r = min(n, powerOfFour * 4 - 1);
            ops++;
            res += (r - l + 1) * ops;
            powerOfFour *= 4;
        }
        return res;
    }
    long long minOperations(vector<vector<int>>& queries) {
          long long total = 0;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            total += (getOps(r) - getOps(l - 1) + 1) / 2;
        }
        return total;
    }
};