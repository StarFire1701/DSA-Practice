class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st; // use long long for safety
        for (int num : nums) {
            long long cur = num;
            while (!st.empty()) {
                long long g = gcd(st.back(), cur);
                if (g == 1) break;
                cur = (st.back() / g) * cur; // lcm
                st.pop_back();
            }
            st.push_back(cur);
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};