#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = m * n;

        auto minimumArea = [&](int si, int ei, int sj, int ej) {
            int x1 = INT_MAX, y1 = INT_MAX, x2 = -1, y2 = -1;
            for (int i = si; i <= ei; i++) {
                for (int j = sj; j <= ej; j++) {
                    if (grid[i][j] == 1) {
                        x1 = min(x1, i);
                        y1 = min(y1, j);
                        x2 = max(x2, i);
                        y2 = max(y2, j);
                    }
                }
            }
            if (x1 == INT_MAX) return 0; // no 1 found
            return (x2 - x1 + 1) * (y2 - y1 + 1);
        };

        // Case 1: Horizontal split -> top + two bottom parts
        for (int i = 0; i < m; i++) {
            int top = minimumArea(0, i, 0, n - 1);
            for (int j = 0; j < n; j++) {
                ans = min(ans, top +
                          minimumArea(i + 1, m - 1, 0, j) +
                          minimumArea(i + 1, m - 1, j + 1, n - 1));
            }
        }

        // Case 2: Horizontal split -> bottom + two top parts
        for (int i = 0; i < m; i++) {
            int bottom = minimumArea(i, m - 1, 0, n - 1);
            for (int j = 0; j < n; j++) {
                ans = min(ans, bottom +
                          minimumArea(0, i - 1, 0, j) +
                          minimumArea(0, i - 1, j + 1, n - 1));
            }
        }

        // Case 3: Vertical split -> left + two right parts
        for (int j = 0; j < n; j++) {
            int left = minimumArea(0, m - 1, 0, j);
            for (int i = 0; i < m; i++) {
                ans = min(ans, left +
                          minimumArea(0, i, j + 1, n - 1) +
                          minimumArea(i + 1, m - 1, j + 1, n - 1));
            }
        }

        // Case 4: Vertical split -> right + two left parts
        for (int j = 0; j < n; j++) {
            int right = minimumArea(0, m - 1, j, n - 1);
            for (int i = 0; i < m; i++) {
                ans = min(ans, right +
                          minimumArea(0, i, 0, j - 1) +
                          minimumArea(i + 1, m - 1, 0, j - 1));
            }
        }

        // Case 5: Two horizontal cuts -> three horizontal bands
        for (int i1 = 0; i1 < m; i1++) {
            for (int i2 = i1 + 1; i2 < m; i2++) {
                ans = min(ans,
                          minimumArea(0, i1, 0, n - 1) +
                          minimumArea(i1 + 1, i2, 0, n - 1) +
                          minimumArea(i2 + 1, m - 1, 0, n - 1));
            }
        }

        // Case 6: Two vertical cuts -> three vertical bands
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = j1 + 1; j2 < n; j2++) {
                ans = min(ans,
                          minimumArea(0, m - 1, 0, j1) +
                          minimumArea(0, m - 1, j1 + 1, j2) +
                          minimumArea(0, m - 1, j2 + 1, n - 1));
            }
        }

        return ans;
    }
};
