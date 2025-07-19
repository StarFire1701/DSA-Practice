class Solution{  
  public:  
   static  bool comparision(vector<int>&arr1,vector<int>& arr2){
      return arr1[2] > arr2[2];
    }
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here
        int n=Jobs.size();
        sort(Jobs.begin(),Jobs.end(),comparision);
        int maxdeadline=0;
        for (int i = 0; i < n; i++) {
            maxdeadline = max(maxdeadline, Jobs[i][1]);
        }
        vector<int>ans(maxdeadline+1,-1);
        int totalprofit=0;
        int count=0;
        for(int i=0;i<n;i++){
          int size=Jobs[i][1];
          for(int j=size;j>0;j--){
            if(ans[j]==-1){
              ans[j]=Jobs[i][0];
              totalprofit+=Jobs[i][2];
              count+=1;
              break;
            }
          }
        }
       
        return {count,totalprofit }; 
    }
};