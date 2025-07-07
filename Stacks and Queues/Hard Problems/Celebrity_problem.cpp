//Brute Force
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n=M.size();
        vector<int>knowme(n,0);
        vector<int>iknow(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]==1){
                    knowme[j]++;
                    iknow[i]++;
                }        
                   }
        }
    for(int i=0;i<knowme.size();i++){
        if(knowme[i]==n-1){
            int val=iknow[i];
            if(val==0){
                return i;
            }
        }
    }
    return -1;
    }
};


//Optimal Solution

class Solution {
   public:
    int celebrity(vector<vector<int>> &M) {
        int n=M.size();
        int top=0;
        int bottom =n-1;
        while(top<bottom){
            if(M[top][bottom]==1){
                top++;
            } else if(M[bottom][top]==1){
                bottom--;
            }
            else{
                top++;
                bottom--;
            }
        }

        if(top>bottom) return -1;
        for(int i=0;i<n;i++){
            if(i==top)continue;
            if(M[top][i]==0 && M[i][top]==1){
                continue;
            } else{
                return -1;
            }
        }

        return top;

    }
};
