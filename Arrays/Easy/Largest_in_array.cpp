class Solution {
public:
    int largestElement(vector<int>& nums) {
        int n=nums.size();
        int largest=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>largest){
                largest=nums[i];
            }
        }
        return largest;
    }
};