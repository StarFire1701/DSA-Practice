class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0); // dp[i] = people who learn on day i
        dp[1] = 1;

        long long sharing_sum = 0; // people who can share on current day

        for (int day = 2; day <= n; ++day) {
            // people start sharing after "delay" days
            if (day - delay >= 1) {
                sharing_sum = (sharing_sum + dp[day - delay]) % MOD;
            }
            // people forget after "forget" days
            if (day - forget >= 1) {
                sharing_sum = (sharing_sum - dp[day - forget] + MOD) % MOD;
            }
            dp[day] = sharing_sum;
        }

        // Count those who still know at day n (not forgotten yet)
        long long result = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            if (day >= 1) result = (result + dp[day]) % MOD;
        }

        return (int)result;
    }
};
