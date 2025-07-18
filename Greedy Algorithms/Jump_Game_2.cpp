// Brute Force
class Solution {
public:
    int calc_jump(int index,int jumps,vector<int>&nums){
        if(index>=nums.size()-1) return jumps;
        int mini=INT_MAX;
        for(int i=1;i<=nums[index];i++){
            mini=min(mini,calc_jump(index+i,jumps+1,nums));
        }
        return mini;
    }
    int jump(vector<int>& nums) {
       return calc_jump(0,0,nums); 
    }
};