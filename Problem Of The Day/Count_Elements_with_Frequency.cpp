class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int maxx=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
              if (mpp[nums[i]] > maxx) {
                 maxx = mpp[nums[i]];
            }
        }
        int ans=0;
        
        for(auto it:mpp){
            if(it.second==maxx){
                ans+=it.second;
            }
        }
        return ans;
    }
};