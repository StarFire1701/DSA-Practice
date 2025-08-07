// Greedy Approach -  Wrong but does pass the test case of 100 answer
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int maxfruits=0;
        for(int i=0;i<n;i++){
            maxfruits+=fruits[i][i];
        }
        int row=0;
        int col=n-1;
        int flag=0;
        while(row<n-2){
            if(row==0 && flag==0){
                flag=1;
                maxfruits+=fruits[row][col];
            } else{
                int temp1=fruits[row+1][col];
                 int temp2 = -1;
            if (col > 0) temp2 = max(temp2, fruits[row+1][col-1]);
            if (col < n - 1) temp2 = max(temp2, fruits[row+1][col+1]);

            if (temp2 > temp1) {
                if (col > 0 && fruits[row+1][col-1] == temp2) col--;
                else if (col < n - 1) col++;
            }
             maxfruits+=max(temp2,temp1);
             row++;
            }
        }
        row=n-1;
        col=0;
        flag=0;
        while(col<n-2){
            if(col==0 && flag==0){
                flag=1;
                maxfruits+=fruits[row][col];
            } else{
                int temp1=fruits[row][col+1];
                int temp2 = -1;
            if (row > 0) temp2 = max(temp2, fruits[row-1][col+1]);
            if (row < n - 1) temp2 = max(temp2, fruits[row+1][col+1]);

            if (temp2 > temp1) {
                if (row > 0 && fruits[row-1][col+1] == temp2) row--;
                else if (row < n - 1) row++;
            }

             maxfruits+=max(temp2,temp1);
             col++;
            }
        }
        return maxfruits;
    }
};

// Optimal Solution - Using DP
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;

        for (int i = 0; i < n; i++) {
            res += grid[i][i];
        }

        for (int pass = 0; pass < 2; pass++) {
            if (pass == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        swap(grid[i][j], grid[j][i]);
                    }
                }
            }

            vector<int> prev(n, -1), curr(n, -1);
            prev[n - 1] = grid[0][n - 1];

            for(int row = 1; row < n - 1; row++) {
                fill(curr.begin(), curr.end(), -1);
                for (int i = 0; i < n; i++) {
                    if (prev[i] < 0) continue;
                    if (i > 0) 
                        curr[i - 1] = max(curr[i - 1], prev[i] + grid[row][i - 1]);
                    if (i < n - 1) 
                        curr[i + 1] = max(curr[i + 1], prev[i] + grid[row][i + 1]);
                    curr[i] = max(curr[i], prev[i] + grid[row][i]);
                }
                swap(prev, curr);
            }
            res += prev[n - 1];
        }
        return res;
    }
};