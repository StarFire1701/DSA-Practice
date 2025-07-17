//Brute Force
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            map<int,int>mpp;
            for(int j=i;j<n;j++){
                mpp[nums[j]]++;
                if(mpp.size()==k){
                    cnt+=1;
                } else if(mpp.size()>k){
                    break;
                }
            }
        }
        return cnt;
    }
};

// Optimal Solution

class Solution {
public:
    int calc_subarrays_with_k_distinct(vector<int>&nums,int k){
        if(k<=0) return 0;
        int n=nums.size();
        int cnt=0;
        int left=0;
        int right=0;
        map<int,int>mpp;
        while(right<n){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            if(mpp.size()<=k){
                cnt+=(right-left+1);
            }
            right++;
        }
        return cnt;


    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return ((calc_subarrays_with_k_distinct(nums,k))- (calc_subarrays_with_k_distinct(nums,k-1)));
    }
};