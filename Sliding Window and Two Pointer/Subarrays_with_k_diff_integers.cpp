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