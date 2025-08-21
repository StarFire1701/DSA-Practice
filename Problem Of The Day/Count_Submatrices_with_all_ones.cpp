class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            // build histogram (DP step)
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }

            // use monotonic stack to count rectangles in O(n)
            stack<int> st;
            vector<int> sum(n, 0);

            for (int j = 0; j < n; j++) {
                while (!st.empty() && height[st.top()] >= height[j]) {
                    st.pop();
                }

                if (!st.empty()) {
                    int prev = st.top();
                    sum[j] = sum[prev] + height[j] * (j - prev);
                } else {
                    sum[j] = height[j] * (j + 1);
                }

                ans += sum[j];
                st.push(j);
            }
        }
        return ans;
    }
};