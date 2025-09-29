class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
      int n = values.size();
        // dp[i][j] will store the minimum score for polygon from vertex i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // l is the length of the subpolygon
        for (int l = 2; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }

        return dp[0][n-1];  
    }
};