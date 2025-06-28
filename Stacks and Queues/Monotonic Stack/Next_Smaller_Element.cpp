//Optimal solution
class Solution{
public:
    vector<int> nextsmallerElements(vector<int>& nums){
        // arr1= [4,2,5,6,1,2]
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                ans[i]=nums[i];
                st.push(nums[i]);
                continue;
            }
            while(!st.empty() && st.top()>=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(nums[i]);
        }
        return ans;
    }

};