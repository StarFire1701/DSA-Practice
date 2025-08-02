//Threshold Majority Queries
// Brute Force
int compute_major(vector<int>&query,vector<int>&nums){
    map<int,int>mpp;
    for(int i=query[0];i<=query[1];i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        if(it.second >= query[2]){
            return it.first;
        }
    }
    return -1;
}
vector<int>subarrayMajority(vector<int>&nums,vector<vector<int>>&queries){
    int n=queries.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(compute_major(queries[i],nums));
    }
    return ans;
}