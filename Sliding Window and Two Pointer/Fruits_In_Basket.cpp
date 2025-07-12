// Brute Force

class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        //your code goes here
        int n=fruits.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
          int temp=-1;
          for(int j=i;j<n;j++){
            if(fruits[j]==fruits[i]){

            } else if(fruits[j]!=fruits[i] && temp==-1){
              temp=fruits[j];
            } else if(fruits[j]!=fruits[i] && fruits[j]==temp){

            } else{
              break;
            }
            maxlen=max(maxlen,j-i+1);
          }
        }
        return maxlen;
    }
};

//Better Solution

class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        //your code goes here
        int n=fruits.size();
        int left=0;
        int right=0;
        int maxlen=0;
        map<int,int>mpp;
        while(right<n){
          mpp[fruits[right]]++;
          while(mpp.size()>2){
            mpp[fruits[left]]--;
            if(mpp[fruits[left]]==0){
              mpp.erase(fruits[left]);
            }
            left++;
          }
          if(mpp.size()<=2){
            maxlen=max(maxlen,right-left+1);
          }
          right++;
        }
        return maxlen;
    }
};

// Optimal Solution

class Solution {
   public:
    int totalFruits(vector<int>& fruits) {
        // your code goes here
        int n = fruits.size();
        int left = 0;
        int right = 0;
        int maxlen = 0;
        map<int, int> mpp;
        while (right < n) {
            mpp[fruits[right]]++;
            if (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0) {
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            if (mpp.size() <= 2) {
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};