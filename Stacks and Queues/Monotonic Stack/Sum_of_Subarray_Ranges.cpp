// Brute Force
// Generating all possible subarrays, find the largest and smallest amongst them to calculate the range and then add up that range for every subarray.
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int largest=nums[i];
            int smallest=nums[i];
            for(int j=i;j<n;j++){
                largest=max(largest,nums[j]);
                smallest=min(smallest,nums[j]);
                ans=ans+(largest-smallest);
            }
            
        }
        return ans;
    }
};

// Optimal Solution

class Solution {
public:
vector<int>prev_small_sum(vector<int>&nums,int n){
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}

vector<int>next_small_sum(vector<int>&nums,int n){
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        ans[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return ans;
}


vector<int>pre_greater_sum(vector<int>&nums,int n){
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<=nums[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}

vector<int>nex_greater_sum(vector<int>&nums,int n){
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<nums[i]){
            st.pop();
        }
        ans[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return ans;
}

long long sum_subarray_mini(vector<int>&nums){
        int n = nums.size();
        vector<int>prev_smaller_sum=prev_small_sum(nums,n);
        vector<int>next_smaller_sum=next_small_sum(nums,n);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=1LL*nums[i]*((next_smaller_sum[i]-i)*(i-prev_smaller_sum[i]));
        }
        return sum;
    }

    long long sum_subarray_maxi(vector<int>&nums){
       int n = nums.size();
        vector<int>prev_greater_sum=pre_greater_sum(nums,n);
        vector<int>next_greater_sum=nex_greater_sum(nums,n);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=1LL*nums[i]*((next_greater_sum[i]-i)*(i-prev_greater_sum[i]));
        }
        return sum; 
    }
    long long subArrayRanges(vector<int>& nums) {
        return (sum_subarray_maxi(nums)-sum_subarray_mini(nums));
    }

    
};