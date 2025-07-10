class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int maxlen=0;
        int left=0;
        int right=0;
        int zeroes=0;
        while(right<n){
            if(nums[right]==1){
               
            } else if(nums[right]==0 and zeroes<k){
                zeroes++;
            } else{
                while(nums[left]!=0){
                    left++;
                }
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};