class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         int n = triangle.size();
        // dp array with last row of triangle
        vector<int> dp(triangle.back());

        // Start from second last row, go upwards
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0]; // Top element contains min path sum
    }
};