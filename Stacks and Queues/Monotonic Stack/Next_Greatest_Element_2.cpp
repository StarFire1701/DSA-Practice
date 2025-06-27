//Brute Force
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0;i<n;i++){
            int temp = -1;

            // Search on right
            for(int j = i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    temp = j;
                    break;
                }
            }

            //Search on left
            if(temp == -1){
            for(int j = 0;j<i;j++){
                if(nums[j]>nums[i]){
                    temp = j;
                    break;
                }
            }
            }

            int ans1 = (temp==-1)?-1:nums[temp];
            ans.push_back(ans1);
        }
        return ans;
    }
};

//Better solution
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            int temp = -1;
            for(int j=i+1;j<= i+n-1;j++){
                if(nums[i]<nums[j%n]){
                    temp=j%n;
                    break;
                }
            }
            temp = (temp==-1) ?-1:nums[temp];
            ans.push_back(temp);
        }
        return ans;

    }
};

//Optimal Solution

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>ans;
        for(int i=(2*n-1);i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                int temp = st.empty()?-1:st.top();
                ans.push_back(temp);
              }
              st.push(nums[i%n]);
            }
        

        reverse(ans.begin(),ans.end());
        return ans;
    }
};