// Brute Force

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>ans;
        for(int i = 0;i<n1;i++){
            int temp = -1;
            int var = 0;
            for(int j = 0;j<n2;j++){
                if(nums2[j]==nums1[i]){
                    var++;
                    break;
                }
                var++;
            }
            while(var<n2){
                if(nums2[var]>nums1[i]){
                    temp = var;
                    break;
                }
                var++;
            }
           int ans1=(temp==-1)? -1: nums2[temp];
            ans.push_back(ans1);
        }
        return ans;
    }
};

// Optimal Solution

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int,int> mpp;
        vector<int>ans;
        stack<int>st;

        for(int i = n2 - 1; i >= 0; i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            mpp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Now time to retrieve it back from the map

        for(auto it: nums1){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};