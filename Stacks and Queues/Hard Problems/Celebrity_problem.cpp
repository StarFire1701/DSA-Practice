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
