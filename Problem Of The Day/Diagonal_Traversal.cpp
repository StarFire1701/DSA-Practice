class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;
        for(int d=0;d<n+m-1;d++){
            vector<int>intermediate;
            int row=(d<m)?0:d-m+1;
            int col=(d<m)?d:m-1;
            while(row<n && col>=0){
                intermediate.push_back(mat[row][col]);
                row++;
                col--;
            }
            if(d%2==0){
                reverse(intermediate.begin(),intermediate.end());
            }
            ans.insert(ans.end(),intermediate.begin(),intermediate.end());
        }
        return ans;
        
    }
};