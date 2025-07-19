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

//Optimal Solution

class Solution {
public:
    int jump(vector<int>& nums) {
       int n=nums.size();
       int left=0;
       int right=0;
       int jumps=0;
       while(right<n-1){
        int maxplace=0;
        for(int i=left;i<=right;i++){
            maxplace=max(i+nums[i],maxplace);
            }
            left=right+1;
            right=maxplace;
            jumps=jumps+1;
       } 
       return jumps;
    }
};