//Brute Force
//Generating all the possible subarrays.
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            const int MOD = 1e9 + 7;
            long long sum = 0;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    int mini=INT_MAX;
                    for(int k=i;k<=j;k++){
                        mini=min(mini,arr[k]);
                    }
                    sum=(sum+mini)%MOD;
                }
            }
            return sum;
    }
};

// Better Solution

//Generating all the possible subarrays.
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            const int MOD = 1e9 + 7;
            long long sum = 0;
            for(int i=0;i<n;i++){
                int mini=arr[i];
                for(int j=i;j<n;j++){
                    mini=min(mini,arr[k]);
                    sum=(sum+mini)%MOD;
                }
            }
            return sum;
    }
};



//Optimal
class Solution {
public:
    vector<int> prev_smaller_element(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> next_smaller_element(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        long long sum = 0;

        vector<int> prev = prev_smaller_element(arr, n);
        vector<int> next = next_smaller_element(arr, n);

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + (arr[i] * left % MOD) * right % MOD) % MOD;
        }
        return (int)sum;
    }
};
