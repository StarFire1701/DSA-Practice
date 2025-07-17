class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max=0;
        int jumps=0;
        for(int i=0;i<n;i++){
            if(i>max){
                return false;
            }
            if(jumps+nums[i]>max){
                max=jumps+nums[i];
            }
             jumps+=1;
        }
        return true;
    }
};