// Brute Force
class Solution{
public:
    int totalFruit(vector<int>&fruits){
        int n=fruits.size();
        if(n==0)return 0;
        if(n==1)return 1;
        int maxlen=0;
        for(int i=0;i<n;i++){
            int temp=-1;
            for(int j=i+1;j<n;j++){
                if(nums[j]==nums[i]){

                } else if(nums[j]!=nums[i] && temp=-1){
                    temp=nums[j];
                } else if(nums[j]!=nums[j] && nums[j]==temp){

                }
                else {
                    break;
                }
                maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }

};

//Better Solution
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n==0)return 0;
        if(n==1)return 1;
        map<int,int>mpp;
        int left=0,right=0;
        int maxlen=0;
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
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n==0)return 0;
        if(n==1)return 1;
        map<int,int>mpp;
        int left=0,right=0;
        int maxlen=0;
        while(right<n){
            mpp[fruits[right]]++;
            if(mpp.size()>2){
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