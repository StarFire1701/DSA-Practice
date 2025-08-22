class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int x1=n;
        int x2=-1;
        int y1=m;
        int y2=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    x1=min(x1,i);
                    y1=min(y1,j);
                    x2=max(x2,i);
                    y2=max(y2,j);
                }
            }
        }
        if(x2<x1 || y2<y1) return 0;
        return (x2-x1+1)*(y2-y1+1);
    }
};