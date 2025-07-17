class Solution {
  public:
    long long solve(vector<int>& bt) {
        //your code goes here
        int n=bt.size();
        sort(bt.begin(),bt.end());
        long long waittime=0;
        long long totaltime=0;
        for(int i=0;i<n;i++){
          waittime+=totaltime;
          totaltime+=bt[i];

        }
        
        return (waittime/n);
    }
};