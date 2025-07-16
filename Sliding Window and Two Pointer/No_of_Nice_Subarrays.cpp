// Optimal Directly from pattern.
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
            sum+=nums[right]%2;
            while(sum>goal){
                sum=sum-nums[left]%2;
                left++;
            }
            if(sum<=goal){
                cnt+=right-left+1;
            }
            right++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return ((compute_no_of_subarrays(nums,k))-(compute_no_of_subarrays(nums,k-1)));
    }
};