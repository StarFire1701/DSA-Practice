class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n));
        unordered_map<int, vector<int>> diag;

        // Collect diagonals
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                diag[i - j].push_back(grid[i][j]);
            }
        }

        // Sort diagonals properly
        for (auto& [key, vec] : diag) {
            if (key >= 0) {
                sort(vec.begin(), vec.end(), greater<int>()); // descending
            } else {
                sort(vec.begin(), vec.end()); // ascending
            }
        }

        // Fill back respecting traversal order
        unordered_map<int, int> idx; // track position in each diagonal
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int key = i - j;
                ans[i][j] = diag[key][idx[key]++];
            }
        }

        return ans; 
    }
};