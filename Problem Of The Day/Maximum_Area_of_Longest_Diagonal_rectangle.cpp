class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        long long ans = 0;
        long long diagonal = 0;
        
        for (int i = 0; i < n; i++) {
            long long temp = 1LL * dimensions[i][0] * dimensions[i][0] + 
                             1LL * dimensions[i][1] * dimensions[i][1];
            long long area = 1LL * dimensions[i][0] * dimensions[i][1];
            
            if (temp > diagonal || (temp == diagonal && area > ans)) {
                diagonal = temp;
                ans = area;
            }
        }
        
        return (int)ans;
    }
};
