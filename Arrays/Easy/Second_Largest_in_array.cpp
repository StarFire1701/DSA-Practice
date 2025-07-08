class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
      int largest=nums[0];
      int slargest=-1;
      int n=nums.size();
      for(int i=1;i<n;i++){
        if(nums[i]>largest){
            slargest=largest;
            largest=nums[i];
        } else if(nums[i]<largest && nums[i]>slargest){
            slargest=nums[i];
        } else{
            continue;
        }
      }

      return slargest;
        }
};