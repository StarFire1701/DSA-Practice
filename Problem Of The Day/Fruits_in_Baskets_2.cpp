// Brute Force

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
      int n=fruits.size();
      vector<int>temp(n,0);
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(fruits[i]<=baskets[j] && temp[j]==0){
                temp[j]=-1;
                break;
            }
        }
      }
      int cnt=0;
      for(int i=0;i<n;i++){
        if(temp[i]==0)cnt++;
      }  
      return cnt;
    }
};

//TC -  o(n2) + o(n) SC -o(n)