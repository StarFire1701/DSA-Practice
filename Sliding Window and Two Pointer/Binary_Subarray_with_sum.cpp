// Brute Force
class Solution {
public:
    int compute_no_of_subarrays(vector<int>&nums,int goal){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==goal){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};


//Better Solution

class Solution {
public:
    int compute_no_of_subarrays(vector<int>&nums,int goal){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==goal){
                    cnt+=1;
                } else if(sum>goal){
                    break;
                }
            }
        }
        return cnt;
    }
};

//Optimal Solution
class Solution {
public:
    int compute_no_of_subarrays(vector<int>&nums,int goal){
        if(goal<0)return 0;
        int left=0;
        int right=0;
        int n=nums.size();
        int sum=0;
        int cnt=0;
        while(right<n){
            sum+=nums[right];
            while(sum>goal){
                sum=sum-nums[left];
                left++;
            }
            if(sum<=goal){
                cnt+=right-left+1;
            }
            right++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (compute_no_of_subarrays(nums,goal)-compute_no_of_subarrays(nums,goal-1));
    }
};